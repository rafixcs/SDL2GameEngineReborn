#ifndef __ENGINE__
#define __ENGINE__

#include <memory>

namespace Engine 
{
    class RebornEngine
    {
        private:
            RebornEngine() {}
            auto initialize() -> void;

        public:
            static auto Build() -> std::shared_ptr<RebornEngine>;
            auto Run() -> void;
    };

}


#endif