#include <stdio.h>
#include <string.h>

#define VEL 20

typedef struct {
    char *typ;
    int dmg;
    int armor;
    int hp;
    int stamina;
} POSTAVA;

void login (char *name) {
        printf("Enter your name: ");
        scanf("%20[^\n]s", name);
}

void choosing_a_hero(POSTAVA postavy[3], int *option) {
    printf("Pick hero you want:\n");
    
    for(int i=0;i<3;i++) {
        printf("\t%d) %s\n", i+1, postavy[i].typ);
    }
    
    do {
        scanf("%d", option);
    } while (*option <= 1 && *option >= 3);
}

void stats_for_monsters (POSTAVA monsters[3]) {
    monsters[0].typ = "Kikimora";
    monsters[0].dmg = 0;
    monsters[0].hp = 0;
    monsters[0].armor = 0;
    monsters[0].stamina = 0;

    monsters[1].typ = "Vampire";
    monsters[1].dmg = 0;
    monsters[1].hp = 0;
    monsters[1].armor = 0;
    monsters[1].stamina = 0;

    monsters[2].typ = "Lawyer";
    monsters[2].dmg = 0;
    monsters[2].hp = 0;
    monsters[2].armor = 0;
    monsters[2].stamina = 0;
}

void stats (POSTAVA postavy[3]) {
    postavy[0].typ = "Tank";
    postavy[0].dmg = 0;
    postavy[0].hp = 0;
    postavy[0].armor = 0;

    postavy[1].typ = "Assassin";
    postavy[1].dmg = 0;
    postavy[1].hp = 0;
    postavy[1].armor = 0;

    postavy[2].typ = "Mage";
    postavy[2].dmg = 0;
    postavy[2].hp = 0;
    postavy[2].armor = 0;
}

int main() {
    char name[VEL];
    int option;
    POSTAVA postavy[3];

    login (name);
    

    stats(postavy);
    choosing_a_hero(postavy, &option);

    printf("Your choice: %s\n", postavy[option-1].typ);

    return 0;
}
