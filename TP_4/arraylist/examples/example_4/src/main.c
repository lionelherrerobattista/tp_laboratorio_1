/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"



int main(void)
{
        //probar los tests hasta que llegue al 100%
        startTesting(1);//prueba al_newArray 100%
        startTesting(2);//prueba al_add 100%
        startTesting(3);//prueba al_delete 100%
        startTesting(4);//prueba al_len 100%
        startTesting(5);//prueba al_get 100%
        startTesting(6);//prueba al_contains 100%
        startTesting(7);//prueba al_set 100%
        startTesting(8);//prueba al_remove 100%
        startTesting(9);//prueba al_clear 100%
        startTesting(10);//prueba al_clone 100%
        startTesting(11);//prueba al_push 100%
        startTesting(12);//prueba al_indexOf 100%
        startTesting(13);//prueba al_isEmpty 100%
        startTesting(14);//prueba al_pop 100%
        startTesting(15);//al_subList %100
        startTesting(16);//al_containsAll %100
        startTesting(17);//al_sort 100%

    return 0;
}





