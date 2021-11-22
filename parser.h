#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* 
 * Struktura przechowująca podstawowe parametry sczytane z sekwencji protokołu NMEA 0183
 */

struct Info_From_NMEA{
double Latitude[2];
double Longitude[2];
int Number_of_satellites;
double  Altitude;
};

/*
 * Funkcja pełniąca funkcję prasera NMEA
 *
 * Zwraca true w przypadku prawidłowego zakończeni 
 */
bool NMEA_parser(const char *NMEA_message);

/*
 * Funkcja licząca sumę kontrolną
 */
int checksum(const char *s);

/*
 * Funkcja konwertująca zapis liczby z Hex na Decimal
 */
int HextoDec(char *Hex);