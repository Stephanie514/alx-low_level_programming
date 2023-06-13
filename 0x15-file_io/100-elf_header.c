#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validElf(unsigned char *elf_tab);
void dispMagic(unsigned char *elf_tab);
void dispClass(unsigned char *elf_tab);
void dispData(unsigned char *elf_tab);
void dispVersion(unsigned char *elf_tab);
void dispOsabi(unsigned char *elf_tab);
unsigned char elf_tab[EI_NIDENT];
ssize_t bytes_read;
/**
 * validElf - Validates if the file is an ELF file.
 * @elf_tab: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void validElf(unsigned char *elf_tab)
{
int a;

for (a = 0; a < 4; a++)
{
if (elf_tab[a] != 127 &&
elf_tab[a] != 'E' &&
elf_tab[a] != 'L' &&
elf_tab[a] != 'F')
{
fprintf(stderr, "Error: Not an ELF file\n");
exit(98);
}
}
}
/**
 * dispMagic - Prints the magic numbers of the ELF header.
 * @elf_tab: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void dispMagic(unsigned char *elf_tab)
{
int a;

printf(" Magic: ");
for (a = 0; a < 4; a++)
{
printf("%02x", elf_tab[a]);
if (a == 3)
printf("\n");
else
printf(" ");
}
}
/**
 * dispClass - Prints the class of the ELF header.
 * @elf_tab: A pointer to an array containing the ELF class.
 */
void dispClass(unsigned char *elf_tab)
{
printf(" Class: ");
switch (elf_tab[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", elf_tab[EI_CLASS]);
break;
}
}
/**
 * dispData - Prints the data encoding of the ELF header.
 * @elf_tab: A pointer to an array containing the ELF class.
 */
void dispData(unsigned char *elf_tab)
{
printf(" Data: ");
switch (elf_tab[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", elf_tab[EI_DATA]);
break;
}
}
/**
 * dispVersion - Display the ELF version information.
 *
 * @elf_tab: The ELF header table.
 */
void dispVersion(unsigned char *elf_tab)
{
printf(" Version: %d", elf_tab[EI_VERSION]);
switch (elf_tab[EI_VERSION])
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
 * dispOsabi - Display the OS/ABI information of the ELF file.
 *
 * This function takes a pointer to the ELF header table and
 * displays the OS/ABI information contained in the header.
 *
 * @elf_tab: - Pointer to the ELF header table.
 */
void dispOsabi(unsigned char *elf_tab)
{
printf(" OS/ABI: ");
switch (elf_tab[EI_OSABI])
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
default:
printf("<unknown: %x>\n", elf_tab[EI_OSABI]);
break;
}
}
/**
 * disp_abi - Prints the ABI version of the ELF header.
 * @e_ident:  pointer to an array containing the ELF ABI version.
 */
void disp_abi(unsigned char *e_ident)
{
printf(" ABI Version: %d\n",
e_ident[EI_ABIVERSION]);
}
/**
 * disp_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void disp_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)

e_type >>= 8;
printf(" Type: ");
switch (e_type)
{
case ET_NONE:
printf("NONE (None)\n");
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
 * disp_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void disp_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf(" Entry point address: ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);
else
printf("%#lx\n", e_entry);
}
/**
 * end_elf - Closes an ELF file.
 * @e: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void end_elf(int e)
{
if (close(e) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", e);
exit(98);
}
}
/**
 * main - Entry point of the program.
 *
 * This function is the entry point of the program. It takes
 * command-line arguments and processes the ELF file specified
 * as a command-line argument.
 *
 * @argc:  The number of command-line arguments.
 * @argv:  An array of strings containing the command-line arguments.
 *
 * Return: Returns 0 on successful execution, otherwise returns an error code.
 */
int main(int argc, char *argv[])
{
unsigned char elf_tab[EI_NIDENT];
ssize_t bytes_read;
const char *elf_file = argv[1];
int file = open(elf_file, O_RDONLY);

if (argc < 2)
{
printf("Usage: %s <elf_file>\n", argv[0]);
exit(1);
}
file = open(argv[1], O_RDONLY);
if (file < 0)
{
perror("Failed to open file");
exit(1);
}
bytes_read = read(file, elf_tab, EI_NIDENT);
if (bytes_read != EI_NIDENT)
{
printf("Failed to read ELF header\n");
exit(1);
}
validElf(elf_tab);
dispMagic(elf_tab);
dispClass(elf_tab);
dispData(elf_tab);
close(file);
return (0);
}
