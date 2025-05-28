#include "../include/Serializer.hpp"

int main(void)
{
    Data data;
    data.content = 42;

    Data* data_p = &data;
    uintptr_t data_ip = Serializer::serialize(data_p);
    Data* data_pv2 = Serializer::deserialize(data_ip);
    std::cout << "first:\t" << data_p << " - " << data_p->content << std::endl;
    std::cout << "second:\t" << data_pv2 << " - " << data_pv2->content << std::endl;
    return 0;
}
