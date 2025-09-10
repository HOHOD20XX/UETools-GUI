#include "Math.h"






SDK::FVector Math::NormalizeVector(const SDK::FVector& vector)
{
    float vectorLengthSquared = (vector.X * vector.X) + (vector.Y * vector.Y) + (vector.Z * vector.Z);
    if (vectorLengthSquared < 0.01f)
        return SDK::FVector();

    float vectorLengthInverted = 1.0f / sqrt(vectorLengthSquared);
    return vector * vectorLengthInverted;
}




uint32_t Math::Seconds_ToMilliseconds(const double& seconds)
{
    return static_cast<uint32_t>(std::lround(seconds * 1000.0));
}
