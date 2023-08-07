#include "main.h"
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * magic_ELF - this checks for ELF file.
 * @e_ident: this points to the array of ELF magic numbers.
 *
 * Return: always 0.
 * or exit with ERROR msg, code 98.
 */
void magic_ELF(unsigned char *e_ident)
{
int a;

for (a = 0; a < 4; a++)
{
if (e_ident[a] != 127 && e_ident[a] != 'E' &&
e_ident[a] != 'L' && e_ident[a] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
 * find_magic_num - function that prints the magic numbers of an ELF_H
 * @e_ident: this one points to the array of ELF magic numbers
 *
 * Return: always 0
 */
void find_magic_num(unsigned char *e_ident)
{
int NUM;

printf("  Magic:   ");

for (NUM = 0; NUM < EI_NIDENT; NUM++)
{
printf("%02x", e_ident[NUM]);
if (EI_NIDENT - 1 == NUM)
printf("\n");
else
printf(" ");
}
}

/**
 * find_class - prints the identified binary architecture(class) of ELF_H
 * @e_ident: this points to the array of the ELF classes.
 *
 * Return: always 0.
 */
void find_class(unsigned char *e_ident)
{
printf("  Class: ");

switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("                            Invalid\n");
break;
case ELFCLASS32:
printf("                            ELF32\n");
break;
case ELFCLASS64:
printf("                            ELF64\n");
break;
default:
printf("                            <unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * find_data - prints the encoded data of processor in ELF_H (endianness)
 * @e_ident: this points to array of ELF processor data.
 *
 * Return: always 0.
 */

void find_data(unsigned char *e_ident)
{
printf("  Data: ");

switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("                             Unknown data format\n");
break;
case ELFDATA2LSB:
printf("                             2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("                             2's complement, big endian\n");
break;
default:
printf("                             <unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * get_version - function that prints the version specification in ELF_H
 * @e_ident: points to an array of ELF versions
 *
 * Return: always 0.
 */
void get_version(unsigned char *e_ident)
{
printf("  Version:                           %d", e_ident[EI_VERSION]);

switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
case 2:
printf(" (current)\n");
break;
default:
printf(" (invalid)\n");
break;
}
}

/**
 * find_osabi - function which prints the identified OS/ABI in ELF_H
 * @e_ident: points to an array of ELF OS/ABI identifiers
 *
 * Return: Always 0
 */
void find_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:");

switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("                            UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("                            UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("                            UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("                            UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("                            UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("                            UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("                            UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("                            UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("                            ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("                            Standalone App\n");
break;
default:
printf("                            <unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
 * find_abi - function that prints the target ABI version in ELF_H
 * @e_ident: this points to an array of ELF ABI versions
 *
 * Return: Always 0.
 */
void find_abi(unsigned char *e_ident)
{
printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * get_type - function which prints the identified type in ELF_H
 * @e_type: this is the ELF type
 * @e_ident: this points to an array of ELF types
 *
 * Return: Always 0.
 */
void get_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

printf("  Type: ");

switch (e_type)
{
case ET_NONE:
printf("                             NONE (None)\n");
break;
case ET_REL:
printf("                             REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("                             EXEC (Executable file)\n");
break;
case ET_DYN:
printf("                             DYN (Shared object file)\n");
break;
case ET_CORE:
printf("                             CORE (Core file)\n");
break;
default:
printf("                             <unknown: %x>\n", e_type);
}
}

/**
 * find_entaddress - function that prints the virtual address in ELF_H on entry
 * @e_entry: this is virtual address of the ELF entry point
 * @e_ident: this points to an array of entry options
 *
 * Return: Always 0.
*/
void find_entaddress(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address: ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}

if (e_ident[EI_CLASS] == ELFCLASS32)
printf("              %#x\n", (unsigned int)e_entry);

else
printf("              %#lx\n", e_entry);
}

/**
 * main - Main function which displays the information contained in the
 * ELF header at the start of an ELF file.
 * @ac: no. of arguments supplied to the program.
 * @av: this is an array of pointers to the arguments
 *
 * Return: 0(success)
 * or ERROR messages
 */
int main(int ac __attribute__((__unused__)), char *av[])
{
Elf64_Ehdr *hdrr;
int fil, _read;

fil = open(av[1], O_RDONLY);
if (fil == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
exit(98);
}
hdrr = malloc(sizeof(Elf64_Ehdr));
if (hdrr == NULL)
{
close(fil);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
exit(98);
}
_read = read(fil, hdrr, sizeof(Elf64_Ehdr));
if (_read == -1)
{
free(hdrr);
close(fil);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", av[1]);
exit(98);
}

magic_ELF(hdrr->e_ident);
printf("ELF Header:\n");
find_magic_num(hdrr->e_ident);
find_class(hdrr->e_ident);
find_data(hdrr->e_ident);
get_version(hdrr->e_ident);
find_osabi(hdrr->e_ident);
find_abi(hdrr->e_ident);
get_type(hdrr->e_type, hdrr->e_ident);
find_entaddress(hdrr->e_entry, hdrr->e_ident);

free(hdrr);
close(fil);
return (0);
}
