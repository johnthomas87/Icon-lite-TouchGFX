#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdint.h>
#include <inttypes.h>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void SendRS232(uint8_t value);
protected:
    ModelListener* modelListener;
    //char* RData;
    char RData[257];
};

#endif // MODEL_HPP
