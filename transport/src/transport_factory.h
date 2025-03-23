#ifndef TRANSPORT_FACTORY_H
#define TRANSPORT_FACTORY_H

#include "transport.h"

class TransportFactory
{
public:
    static Transport* createTransport(int type);
};

#endif // TRANSPORT_FACTORY_H
