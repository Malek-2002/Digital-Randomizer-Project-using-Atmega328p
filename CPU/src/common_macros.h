
#ifndef COMMON_MACROS_
#define COMMON_MACROS_
// macro to set bit in a specefic register
#define SET_BIT(R,B) (R |= (1 << B))

// macro to clear bit in a specefic register
#define Clear_BIT(R,B) (R &= ~(1 << B))

#define TOGGLE_BIT(R,B) (R ^= (1 << B))

// macro to check if bit is HIGH in a specefic register
#define IS_BIT_HIGH(R,B) (R & (1 << B))

// macro to check if bit is LOW in a specefic register
#define IS_BIT_LOW(R,B) (!(R & (1 << B)))

#define SET_REG(R) (R = 0xFF)

#define ClEAR_REG(R) (R = 0)

#define IS_REG_HIGH(R) (R == 0xFF)

#define IS_REG_LOW(R) (R == 0)


#endif