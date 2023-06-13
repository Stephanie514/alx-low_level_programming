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
void disp_abi(unsigned char *elf_tab);
void disp_type(unsigned int e_type, unsigned char *e_ident);
void disp_entry(unsigned long int e_entry, unsigned char *e_ident);
void end_elf(int e);

/**
* validElf - Validates if the file is an ELF file.
* @elf_tab: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not an ELF file - exit code 98.
*/
void validElf(unsigned char *elf_tab)
{
if (elf_tab[EI_MAG0] != ELFMAG0 || elf_tab[EI_MAG1] != ELFMAG1 ||
elf_tab[EI_MAG2] != ELFMAG2 || elf_tab[EI_MAG3] != ELFMAG3)
{
fprintf(stderr, "Error: Not an ELF file\n");
exit(98);
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
for (a = 0; a < EI_NIDENT; a++)
{
printf("%02x", elf_tab[a]);
if (a != EI_NIDENT - 1)
printf(" ");
}
printf("\n");
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
* dispVersion - Prints the version of the ELF header.
* @elf_tab: A pointer to an array containing the ELF version.
*/
void dispVersion(unsigned char *elf_tab)
{
printf(" Version: %d", elf_tab[EI_VERSION]);
printf("\n");
}

/**
* dispOsabi - Prints the OS/ABI of the ELF header.
* @elf_tab: A pointer to an array containing the ELF OS/ABI.
*/
void dispOsabi(unsigned char *elf_tab)
{
printf(" OS/ABI: ");
switch (elf_tab[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("Sun Solaris\n");
break;
case ELFOSABI_AIX:
printf("IBM AIX\n");
break;
case ELFOSABI_IRIX:
printf("SGI Irix\n");
break;
case ELFOSABI_FREEBSD:
printf("FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("Compaq TRU64 UNIX\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone (embedded) application\n");
break;
default:
printf("<unknown: %x>\n", elf_tab[EI_OSABI]);
break;
}
}

/**
* disp_abi - Prints the ABI version of the ELF header.
* @elf_tab: A pointer to an array containing the ELF ABI version.
*/
void disp_abi(unsigned char *elf_tab)
{
printf(" ABI Version: %d", elf_tab[EI_ABIVERSION]);
printf("\n");
}

/**
* disp_type - Prints the type of the ELF header.
* @e_type: The type field of the ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*/
void disp_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_CLASS] == ELFCLASS32)
{
switch (e_type)
{
case ET_NONE:
printf(" Type: NONE (No file type)\n");
break;
case ET_REL:
printf(" Type: REL (Relocatable file)\n");
break;
case ET_EXEC:
printf(" Type: EXEC (Executable file)\n");
break;
case ET_DYN:
printf(" Type: DYN (Shared object file)\n");
break;
case ET_CORE:
printf(" Type: CORE (Core file)\n");
break;
default:
printf(" Type: <unknown: %x>\n", e_type);
break;
}
}
else if (e_ident[EI_CLASS] == ELFCLASS64)
{
switch (e_type)
{
case ET_NONE:
printf(" Type: NONE (None)\n");
break;
case ET_REL:
printf(" Type: REL (Relocatable)\n");
break;
case ET_EXEC:
printf(" Type: EXEC (Executable)\n");
break;
case ET_DYN:
printf(" Type: DYN (Shared object)\n");
break;
case ET_CORE:
printf(" Type: CORE (Core)\n");
break;
default:
printf(" Type: <unknown: %x>\n", e_type);
break;
}
}
}

/**
* disp_entry - Prints the entry point address of the ELF header.
* @e_entry: The entry field of the ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*/
void disp_entry(unsigned long int e_entry, unsigned char *e_ident)
{
if (e_ident[EI_CLASS] == ELFCLASS32)
{
printf(" Entry point address: 0x%x\n", (unsigned int)e_entry);
}
else if (e_ident[EI_CLASS] == ELFCLASS64)
{
printf(" Entry point address: 0x%lx\n", e_entry);
}
}

/**
* end_elf - Prints the endianness of the ELF header.
* @e: The endianness value from the ELF header.
*/
void end_elf(int e)
{
printf(" %s: %s\n", "Endianness", (e == 1) ? "Little endian" : "Big endian");
}

int main(int argc, char **argv)
{
int fd;
unsigned char elf_tab[EI_NIDENT];
ssize_t n_read;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <ELF-file>\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
perror("open");
exit(98);
}

n_read = read(fd, elf_tab, EI_NIDENT);
if (n_read == -1)
{
perror("read");
exit(98);
}
if (n_read != EI_NIDENT)
{
fprintf(stderr, "Error: Unable to read ELF header\n");
exit(98);
}

validElf(elf_tab);
dispMagic(elf_tab);
dispClass(elf_tab);
dispData(elf_tab);
dispVersion(elf_tab);
dispOsabi(elf_tab);
disp_abi(elf_tab);
disp_type(((Elf32_Ehdr *)elf_tab)->e_type, elf_tab);
disp_entry(((Elf32_Ehdr *)elf_tab)->e_entry, elf_tab);
end_elf(((Elf32_Ehdr *)elf_tab)->e_ident[EI_DATA]);

close(fd);
return (0);
}

