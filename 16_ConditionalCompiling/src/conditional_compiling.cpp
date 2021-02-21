
#include "conditional_compiling.h"

#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "=" VALUE(var)

#pragma message(VAR_NAME_VALUE(USE_OCTOMAP))
#pragma message(VAR_NAME_VALUE(USE_VDB_EDT))
#pragma message(VAR_NAME_VALUE(USE_VOXBLOX))

using namespace std;

int main()
{

#if USE_OCTOMAP == 1
    std::cout << "USE_OCTOMAP!" << std::endl;
#elif USE_VDB_EDT == 1
    std::cout << "USE_VDB_EDT!" << std::endl;
#elif USE_VOXBLOX == 1
    std::cout << "USE_VOXBLOX!" << std::endl;
#else
    std::cout << "MAPPING FRAMEWORK NOT SET!" << std::endl;
#endif

    Point p1, p2;

    p1.set(1, 0);
    p2.set(5, -2);

    p1.printP();
    p2.printP();

    return 0;
}