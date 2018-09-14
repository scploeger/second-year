/**
 * @file car.h
 * @author Spencer Ploeger
 * @date October 2017
 * @brief File containing the function definitions for car.c and definition of the car struct
 */


/**
 * Stores basic car information.
 */
typedef struct car {
    char direcTo;
    char instruction;
    double timeArrive;
    double timeFront;
    double timeOut;
} Car;


/**Function to create a new car
 *@param dir - direction of the car
 *@param action - either left, right, or forward
 *@param time - time the car will arrive at the intersection
 *@return a stuct of type car
 **/
Car* createCar( char dir, char action, double time );

/**Function to get the direction of a car
 *@param car - a car to find the direction of
 *@return the direction of the car
 **/
char getDirecTo(Car * c);

/**Function to print the data of a car
 *@param car - the car of which the data is to be printed
 *@post calls the user definde function to print a car
 **/
void printCar(void * c);

/**Function to get the instruction of a car
 *@param car - car to get the instruction of
 *@return the instruction of a given car
 **/
char getInstruction(Car * c);

/**Function to get intersection arrival time of a car
 *@param car - car to get the arrivial time of
 *@return the intersection arrival time
 **/
double getTimeArrive(Car * c);

/**Function to get the time a car exits the intersection
 *@param car - car to get the exit time of
 *@return the intersection exit time
 **/
double getTimeOut(Car * c);

/**Function to get the time a car enters the intersection
 *@param car - car to get the front of the line time of
 *@return the front of the line time
 **/
double getTimeFront(Car * c);

/**Function to delete a car, user defined and passed through
 *@param car - the car to be deleted
 *@post 
 **/
void deleteCar(void * toBeDeleted);

/*this function is not used or defined in this program*/
int compareCar(const void* first, const void* second);