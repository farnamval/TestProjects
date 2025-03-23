#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>

class Transport
{
public:
    virtual ~Transport();
    virtual std::string getName() const = 0;
    virtual int getWheelsCount() const = 0;
    virtual int getMaxSpeed() const = 0;
    virtual void printParameters() const;    
};

class Motorcycle : public Transport
{
public:    
    std::string getName() const override;
    int getWheelsCount() const override;
    int getMaxSpeed() const override;
    int getSeatHeight() const;
    void printParameters() const override;
};

class Scooter : public Transport
{
public:    
    std::string getName() const override;
    int getWheelsCount() const override;
    int getMaxSpeed() const override;
    int getBatteryPower() const;
    void printParameters() const override;
};

class Car : public Transport
{
public:
    std::string getName() const override;
    int getWheelsCount() const override;
    int getMaxSpeed() const override;
    int getTrunkVolume() const;
    void printParameters() const override;
};

class Bus : public Transport
{
public:
    std::string getName() const override;
    int getWheelsCount() const override;
    int getMaxSpeed() const override;
    int getSeatsNumber() const;
    void printParameters() const override;
};

#endif // TRANSPORT_H
