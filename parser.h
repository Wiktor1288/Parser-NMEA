#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


typedef enum {
  N,
  S,
  W,
  E
} Direction;

typedef struct {
int degrees;
double minutes;
Direction direction;
}Coord;


/* 
 * Struktura przechowująca podstawowe parametry sczytane z sekwencji protokołu NMEA 0183
 */
typedef struct {
Coord Latitude;
Coord Longitude;
int Number_of_satellites;
double  Altitude_m;
}NMEA_GGA;

/*
 * Funkcja pełniąca funkcję prasera NMEA
 *
 * Zwraca true w przypadku prawidłowego zakończeni 
 */
bool NMEA_parser(const char *NMEA_message, NMEA_GGA *structure_with_data );

/*
 * Funkcja licząca sumę kontrolną
 */
int checksum(const char *s);

/*
 * Funkcja konwertująca zapis liczby z Hex na Decimal
 */
int HexToDec(char *Hex);

void ShowDataGGA(NMEA_GGA structure_1);