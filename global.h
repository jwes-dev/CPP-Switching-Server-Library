// common
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

using namespace std;

// server
#include <sys/socket.h>
#include <netinet/in.h>

// app includes
#include "Models/models.h"
#include "Includes/references.h"

char* global()
{
    return (char*)"Global Header File V1.0";
}