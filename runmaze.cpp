#include "wall.h"
#include "maze.h"
#include "dlist.h"
#include <iostream>
/********************************************************************/
/*                                                                  */
/*  A1 Part 3: runMaze                                  */
/*                                                                  */
/*  Author1 Name: <name here>                                       */
/*      - class/function list/main author or main checker           */
/*  Author2 Name: <name here>                                       */
/*      - class/function list/main author or main checker           */
/*                                                                  */
/********************************************************************/








int searchPath(Maze& theMaze, DList<int>& list, int startCell, int endCell, int row, int col) {
	DList<int>::const_iterator it;

	//std::cout << "Inside again repetion = " << list.size() << std::endl;

//	std::cout << "Col - " << col << std::endl << "Row - " << row << std::endl << "Cell - " << theMaze.getCell(row, col) << std::endl;

							// gets row of number
	/*
	std::cout << "num rows " << theMaze.numRows() << std::endl;
	std::cout << "num cols " << theMaze.numCols() << std::endl;
	std::cout << "Value of startCell " << startCell << std::endl;
	std::cout << "Row of startCell " << row << std::endl;
	std::cout << "Col of startCell " << col << std::endl;
	*/
	//std::cout << " theMaze.canGo(startCell, startCell++) = " << (theMaze.canGo(startCell, 1) ? ("True") : ("False")) << std::endl;
	//std::cout << "theMaze.getCell(row, col++) = " << theMaze.canGo( 1 , theMaze.getCell(row + 1, col + 1)) << std::endl;


	if (startCell == endCell || list.size() == 0) {
		return 0;
	}
	else if (col != 0 && theMaze.canGo(startCell, theMaze.getCell(row, col - 1)) && !(theMaze.isMarked(theMaze.getCell(row, col - 1))))
	{

		col--;
		startCell = theMaze.getCell(row, col);
		list.push_back(startCell);
		theMaze.mark(startCell);
		//std::cout << "Can go case 4 " << std::endl;
		/*	for (it = list.cbegin(); it != list.cend(); it++) {

				std::cout << "it - " << *it << std::endl;

			}*/
		searchPath(theMaze, list, startCell, endCell, row, col);


	}

	else if (row != 0 && theMaze.canGo(startCell, theMaze.getCell(row - 1, col)) && !(theMaze.isMarked(theMaze.getCell(row - 1, col))))
	{
		row--;
		startCell = theMaze.getCell(row, col);
		list.push_back(startCell);
		theMaze.mark(startCell);
		//std::cout << "Can go case 3 " << std::endl;
			/*	for (it = list.cbegin(); it != list.cend(); it++) {

					std::cout << "it - " << *it << std::endl;

				}*/
		searchPath(theMaze, list, startCell, endCell, row, col);


	}
	else if (row != theMaze.numRows() && theMaze.canGo(startCell, theMaze.getCell(row + 1, col)) && !(theMaze.isMarked(theMaze.getCell(row + 1, col)))) {


		row++;
		startCell = theMaze.getCell(row, col);
		list.push_back(startCell);
		theMaze.mark(startCell);
		//std::cout << "Can go case 2 " << std::endl;
			/*	for (it = list.cbegin(); it != list.cend(); it++) {

					std::cout << "it - " << *it << std::endl;

				}*/

		searchPath(theMaze, list, startCell, endCell, row, col);

	}
	else if (col != theMaze.numCols() && theMaze.canGo(startCell, theMaze.getCell(row, col + 1)) && !(theMaze.isMarked(theMaze.getCell(row, col + 1)))) {
		col++;
		startCell = theMaze.getCell(row, col);
		list.push_back(startCell);
		theMaze.mark(startCell);
		//std::cout << "Can go case 1 " << std::endl;
			/*	for (it = list.cbegin(); it != list.cend(); it++) {

					std::cout << "it - " << *it << std::endl;

				}*/
		searchPath(theMaze, list, startCell, endCell, row, col);




	}


	else {


		list.pop_back();
		it = list.cend();
		--it;

		startCell = *it;







		searchPath(theMaze, list, startCell, endCell, theMaze.getRow(startCell), theMaze.getCol(startCell));


	}


	//std::cout << "LEft " << std::endl;
	return 1;



}











int runMaze(Maze& theMaze, int path[], int startCell, int endCell) {
	DList<int> pathList;
	pathList.push_front(startCell);
	theMaze.mark(startCell);

	searchPath(theMaze, pathList, startCell, endCell, theMaze.getRow(startCell), theMaze.getCol(startCell));
	DList<int>::const_iterator it = pathList.cbegin();



	int i = 0;
	while (it != pathList.cend())
	{
		path[i] = *it;
		i++;
		it++;
	}


	return pathList.size();
}