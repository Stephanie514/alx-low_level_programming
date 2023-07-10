#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validElf(unsigned char *e_ident);
void dispMagic(unsigned char *e_ident);
void dispClass(unsigned char *e_ident);
void dispData(unsigned char *e_ident);
void dispVersion(unsigned char *e_ident);
void disp_abi(unsigned char *e_ident);
void dispOsabi(unsigned char *e_ident);
void disp_type(unsigned int e_type);
void disp_entry(unsigned long int e_entry, unsigned char *e_ident);
void end_elf(int e);

/**
 * validElf - Validates if the file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void validElf(unsigned char *e_ident)
{
int a;

for (a = 0; a < 4; a++)
{
if (e_ident[a] != 127 &&
e_ident[a] != 'E' &&
e_ident[a] != 'L' &&
e_ident[a] != 'F')
{
fprintf(stderr, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
 * dispMagic - Prints the magic numbers of the ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void dispMagic(unsigned char *e_ident)
{
int a;

printf("ELF Header:\n  Magic:   ");

for (a = 0; a < EI_NIDENT; a++)
{
printf("%02x", e_ident[a]);

if (a == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
 * dispClass - Prints the class of the ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void dispClass(unsigned char *e_ident)
{
printf("  Class:                             ");

switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("ELFCLASSNONE\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * dispData - Prints the data encoding of the ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void dispData(unsigned char *e_ident)
{
printf("  Data:                              ");

switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("ELFDATANONE\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_DATA]);
}
}

/**
 * dispVersion - Display the ELF version information.
 *
 * @e_ident: The ELF header table.
 */
void dispVersion(unsigned char *e_ident)
{
printf("  Version:                           %d", e_ident[EI_VERSION]);

switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
 * disp_abi - Prints the ABI version of the ELF header.
 * @e_ident:  pointer to an array containing the ELF ABI version.
 */
void disp_abi(unsigned char *e_ident)
{
printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * dispOsabi - Prints the OS/ABI of the ELF header.
 * @e_ident: A pointer to an array containing the ELF OS/ABI.
 */
void dispOsabi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");

switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("UNIX - ARM architecture\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone (embedded) application\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
 * disp_type - Prints the type of the ELF header.
 * @e_type: The ELF type.
 *
 */
void disp_type(unsigned int e_type)
{
printf("  Type:                              ");

switch (e_type)
{
case ET_NONE:
printf("NONE (No file type)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
}
}

/**
 * disp_entry - Prints the entry point address of the ELF header.
 * @e_entry: The entry point address.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void disp_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address:               ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
printf("0x%lx\n", __builtin_bswap64(e_entry));
else if (e_ident[EI_DATA] == ELFDATA2LSB)
printf("0x%lx\n", e_entry);
}

/**
 * end_elf - Closes the file descriptor.
 * @e: The return value of the close function.
 *
 * Description: If the closing fails - exit code 98.
 */
void end_elf(int e)
{
if (e != 0)
{
fprintf(stderr, "Error closing file\n");
exit(98);
}
}
/**
 * main - Entry point of the program.
 *
 * takes command-line arguments and processes the
 * ELF file specified as a command-line argument.
 *
 * @ac:  The number of command-line arguments.
 * @av:  An array of strings containing the command-line arguments.
 *
 * Return: Returns 0 on successful execution
 * otherwise returns an error code.
 */
int main(int ac, char **av)
{
int fd, e;
unsigned char e_ident[EI_NIDENT];
Elf64_Ehdr *elf_header;

if (ac != 2)
{
fprintf(stderr, "Usage: %s <ELF_file>\n", av[0]);
exit(98);
}

fd = open(av[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error: Cannot open file %s\n", av[1]);
exit(98);
}

e = read(fd, e_ident, EI_NIDENT);
if (e == -1)
{
fprintf(stderr, "Error: Cannot read from file %s\n", av[1]);
close(fd);
exit(98);
}

validElf(e_ident);
dispMagic(e_ident);
dispClass(e_ident);
dispData(e_ident);
dispVersion(e_ident);
disp_abi(e_ident);
dispOsabi(e_ident);

elf_header = (Elf64_Ehdr *)e_ident;
disp_type(elf_header->e_type);
disp_entry(elf_header->e_entry, e_ident);

e = close(fd);
end_elf(e);
return (0);
}

