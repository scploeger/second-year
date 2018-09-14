#include "LinkedListAPI.h"
/**
 * @file fileIO.h
 * @author Spencer Ploeger
 * @date October 2017
 * @brief File containing the function definitions of the function to load text files
 */


/**Function for reading in a list and sorting the car data into four lists depending on their direction of travel
*@pre data should be in correct format 'Direction of travel_action_time of arrival '
*@param filename - the name of the file to be read
*@param northlist - the list to put northbound cars in
*@param southlist - the list to put southbound cars in
*@param eastlist - the list to put eastbound cars in
*@param westlist - the list to put westbound cars in
**/
void loadFile( char * filename, List *northList, List *southList, List *eastList, List *westList );