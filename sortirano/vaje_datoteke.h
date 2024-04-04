
// vaje_datoteke.h

#pragma once

#include <iostream>


struct Oseba {
    char priimek[21];
    int starost;
    float visina;
};

void napolni_osebo(struct Oseba &a) {
    fgets(a.priimek, 20, stdin);
    std::cin >> a.starost;
    std::cin >> a.visina;
    std::cin.ignore();
}

bool enako(struct Oseba a, struct Oseba b) {
    return (
        !strcmp(a.priimek, b.priimek) &&
        a.starost == b.starost && 
        a.visina == b.visina
    );
}