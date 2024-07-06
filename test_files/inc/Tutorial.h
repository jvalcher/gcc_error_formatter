//
// Created by alimovlex
//

//
#ifdef __cplusplus
extern "C" {
#endif
int listFiles();
int fileTest();
int preprocessingTest();
int dataTypeSizeTest();
int localTimeCheck();
void timerFunction(int(func)());
int pointersTest();
int characterSetTest();
int argumentsTest(int args,...);
int sandbox();

//C++ Syntax added to be referenced/built in gtest,
#ifdef __cplusplus
}
#endif
