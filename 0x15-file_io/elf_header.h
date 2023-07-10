#ifndef ELF_HEADER_H
#define ELF_HEADER_H

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

#endif /* ELF_HEADER_H */

