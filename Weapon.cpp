//
// Created by Afik on 05/06/2018.
//

#include "Weapon.h"

Weapon::Weapon(const char* name, Target target, int hit_strength):
    weapon_name(new char[strlen(name)+1]),
    weapon_target(target),
    hit_strength(hit_strength) {
    strcpy(weapon_name, name);
    }

Weapon::~Weapon(){
    delete[] weapon_name;
}

Target Weapon::getTarget() const{
    return weapon_target;
}
int Weapon::getHitStrength() const{
    return hit_strength;
}
int Weapon::getValue() const{
    if (weapon_target == LEVEL){
        return hit_strength;
    }
    if (weapon_target == STRENGTH){
        return hit_strength*2;
    } else {
        return hit_strength*3;
    }
}
bool Weapon::operator==(const Weapon& weapon1) const{
    return weapon1.getValue()==getValue();
}
bool Weapon::operator!=(const Weapon& weapon1)const{
    return weapon1.getValue()!=getValue();
}
bool Weapon::operator<(const Weapon& weapon1)const{
    return getValue()<weapon1.getValue();
}
bool Weapon::operator>(const Weapon& weapon1)const{
    return getValue()>weapon1.getValue();
}
ostream& operator<<(ostream& os, const Weapon& weapon){
    return os << "{weapon name: " << weapon.weapon_name <<
         ", weapon value:" << weapon.getValue() << "}";
}
Weapon::Weapon(const Weapon& weapon):
        weapon_name(new char[strlen(weapon.weapon_name)+1]),
        weapon_target(weapon.weapon_target), hit_strength(weapon.hit_strength) {
    strcpy(weapon_name, weapon.weapon_name);
}
Weapon& Weapon::operator=(const Weapon& weapon){
   if (this == &weapon){
      return *this;
   }
    delete[] weapon_name;
    weapon_name = new char[strlen(weapon.weapon_name)+1];
    strcpy(weapon_name,weapon.weapon_name);
    weapon_target = weapon.weapon_target;
    hit_strength = weapon.hit_strength;
    return *this;
}