//
// Created by Manuel on 10.07.2018.
//


#include <string>
#include <iostream>
#include <HashMap.cpp>

int main() {
    auto *mappo = new HashMap<std::string, int>();
    mappo->add("1", 10);
    mappo->add("2", 20);
    mappo->add("3", 30);
    mappo->add("4", 40);
    mappo->add("4", 44);
    mappo->add("5", 50);
    mappo->add("6", 60);
    mappo->add("7", 70);
    mappo->add("8", 80);
    mappo->add("9", 90);
    mappo->add("10", 100);
    mappo->add("11", 110);
    mappo->add("12", 120);
    std::cout << mappo->get("4") << std::endl;
    std::cout << mappo->get("12") << std::endl;
    return 0;
}