#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "vtIsoSurf.h"


//////////////////////////////////////////////////////////////////
// Read data from "fname"
//
float* read_volume(char* fname, int &xdim, int &ydim, int &zdim)
{
    FILE* in;
    in = fopen(fname, "rb");
    if (in == NULL) {
	printf(" can't open file %s\n", fname);
	exit(0);
    }

    fread(&xdim, sizeof(int), 1, in);
    fread(&ydim, sizeof(int), 1, in);
    fread(&zdim, sizeof(int), 1, in);
    
    printf(" %d %d %d \n", xdim, ydim, zdim); 
    
    int size = xdim*ydim*zdim;
    float *volume = new float[size];
    fread(volume, sizeof(float), size, in);
    fclose(in);
    return(volume);
}


////////////////////////////////

void usage(char *prgm) {    
    printf(" Usage: %s filename output\n", prgm); 
    exit(-1); 
}

//////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    if (argc!=3) usage(argv[0]);
    char *filename = argv[1];
    char *output = argv[2];
    int xdim, ydim, zdim;
    float* volume = read_volume(filename, xdim, ydim, zdim);
    if (volume == NULL) return 0;
    
    vtIsoSurf *iso = new vtIsoSurf(volume, xdim, ydim, zdim);
    iso->set_isov(0.9); 
    iso->execute();
    return 1;
}


