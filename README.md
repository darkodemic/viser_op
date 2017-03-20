# Osnove programiranja - Visoka skola elektrotehnike i racunarstva


Zadatci iz zbirke Osnovi programiranja na jeziku C - VISER

Kod je pisan po C11 standardu. 

Nema kompatabilnost sa starijim standardima kao sto su C89, C90. Primarno promenjive nisu deklarisane na pocetku funkcije nego po potrebi.
Za build je potreban compiler koji ima podrsku za C99 ili novije. Sem toga sve bi trebalo da je po ANSI C standardu.

Binary file-ovi su compile-ovani za x86-64 sisteme (64bit) i nece raditi na x86 sistemima. 
Windows binary file-ovi (.exe) imaju izmenu da im je dodat system("pause"); na kraj kako bi consola ostala otvorena da bi se jasnije video rezultat. 

Linux bin file-ovi nisu dodati jer nema potrebe za njima trenutno ako neko zeli neka napravi issue i dodacu ih.

Licence GPL3

Author: Darko Demić
