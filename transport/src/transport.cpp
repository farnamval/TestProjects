#include <iostream>
#include <string>
#include "transport.h"

Transport::~Transport() = default;

void Transport::printParameters() const
{
    std::cout << "Наименование транспорта: " << getName() << "\n"
              << "Количество колес: " << getWheelsCount() << "\n"
              << "Максимальная скорость: " << getMaxSpeed() << "\n";
}

std::string Motorcycle::getName() const { return "мотоцикл"; }

int Motorcycle::getWheelsCount() const { return 2; }

int Motorcycle::getMaxSpeed() const { return 180; }

int Motorcycle::getSeatHeight() const { return 90; }

void Motorcycle::printParameters() const
{
    Transport::printParameters();
    std::cout << "Высота сиденья: " << getSeatHeight() << "см" << "\n";
}

std::string Scooter::getName() const { return "самокат"; }

int Scooter::getWheelsCount() const { return 2; }

int Scooter::getMaxSpeed() const { return 20; }

int Scooter::getBatteryPower() const { return 4500; }

void Scooter::printParameters() const
{
    Transport::printParameters();
    std::cout << "Емкость батареи: " << getBatteryPower() << "мА·ч" << "\n";
}

std::string Car::getName() const { return "автомобиль"; }

int Car::getWheelsCount() const { return 4; }

int Car::getMaxSpeed() const { return 120; }

int Car::getTrunkVolume() const { return 500; }

void Car::printParameters() const
{
    Transport::printParameters();
    std::cout << "Объем багажника: " << getTrunkVolume() << "л" << "\n";
}

std::string Bus::getName() const { return "автобус"; }

int Bus::getWheelsCount() const { return 4; }

int Bus::getMaxSpeed() const { return 90; }

int Bus::getSeatsNumber() const { return 40; }

void Bus::printParameters() const
{
    Transport::printParameters();
    std::cout << "Количество мест: " << getSeatsNumber() << "\n";
}
