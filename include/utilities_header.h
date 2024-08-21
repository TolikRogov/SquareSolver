const double SS_MIN_VAL = 10e-6;

typedef enum {
    NO_ERROR,
    WRONG_READING,
    WRONG_TEST,
    UNDEFINED_NUMBER_ROOTS
} Errors;

void ClearBuffer();
int NearZero(double n);
const char* ErrorsMessenger(Errors error);
