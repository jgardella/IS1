#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
//#include "ImageFunctions.h
using namespace std;


////////////////////////
// changed read_pgm_image, write_pgm_Uimage functions to work with 2005 version of ifstream
// ppm not updated yet


unsigned char *read_pgm_image(char *fname, int *nx, int *ny)
{
	unsigned char *dummy;
	int i_size, x, y;
	ifstream fin;

	fin.open(fname, ios::binary);
	if (fin == NULL){
		cout << "File I/O error" << endl;
		exit(0);
	}


	char line[110];
	fin.getline(line,100); //read P#
	//printf(line);

	fin.getline(line, 5, ' ');
	//printf(line);

	if(line[0] >= '0' && line[0] <= '9')  // read number
	{
		//printf("\n no comment\n");
		//printf(line);

		x = atoi(line);
	}
	else
	{
		//printf("\n  something else \n");
		//printf(line);
		fin.getline(line, 100);  // read through comment
		fin.getline(line, 5, ' ');
	//	printf(line);
		x = atoi(line);
	}

	//fin >> y >> s; // >> t;
	fin.getline(line, 50);
	y = atoi(line);
	fin.getline(line, 50);
//	cout << "x " << x << " y " << y << endl;
	//cout << "s " << s << endl; // " t " << t << endl;
	while('\n'==fin.peek())
		fin.ignore(1);
	*nx=x; *ny=y;
	i_size=(*nx)*(*ny);
	dummy = new unsigned char [i_size];
	fin.read((char *)dummy, i_size);
	fin.close();

	return(dummy);
}


unsigned char *read_ppm_image(char *fname, int *nx, int *ny)
{
	unsigned char *dummy;
	int i_size, x, y;
	ifstream fin;

	fin.open(fname, ios::binary);
	if (fin == NULL){
		cout << "File I/O error" << endl;
		exit(0);
	}

	char line[110];
	fin.getline(line,100); //read P#

	fin.getline(line, 5, ' ');

	if(line[0] >= '0' && line[0] <= '9')  // read number
		x = atoi(line);
	else
	{
		fin.getline(line, 100);  // read through comment
		fin.getline(line, 5, ' ');
		x = atoi(line);
	}

	//fin >> y >> s; // >> t;
	fin.getline(line, 50);
	y = atoi(line);
	fin.getline(line, 50);

	//cout << "x " << x << " y " << y << endl;
	//cout << "s " << s << endl; // " t " << t << endl;
	while('\n'==fin.peek())
		fin.ignore(1);
	*nx=x; *ny=y;
	i_size=(*nx)*(*ny)*3;
	dummy = new unsigned char [i_size];
	fin.read((char *)dummy, i_size);
	fin.close();

	return(dummy);
}


int write_pgm_Uimage(unsigned char *image, char *fname, int nx, int ny)
{
	ofstream fout;

	//cout << "Writing " << nx << "*" << ny << " image." << endl;

	fout.open(fname, ios::binary);
	if (fout == NULL) {
		cout << "File I/O error" << endl;
		return(0);
	}

	fout << "P5" << endl;
	fout << "# Intermediate image file" << endl;
	fout << nx << " ";
	fout << ny << endl;
	fout << "255" << endl ;


    fout.write((const char *)image, nx * ny * sizeof(unsigned char));
	fout.close();

	/*

	FILE *fout;

	printf("Writing %d*%d image.\n",nx,ny);

	fout = fopen(fname,"wt");
	if (fout == NULL) {
		cout << "File I/O error" << endl;
		return(0);
	}

	fprintf(fout, "P5\n");
	fprintf(fout, "# Intermediate image file\n");
	fprintf(fout, "%d\n", nx);
	fprintf(fout, "%d\n", ny);
	fprintf(fout, "255\n");

	fwrite(image,sizeof(unsigned char),nx*ny,fout);
	fclose(fout);

	*/

	return 1;
}


int write_ppm_Uimage(unsigned char *image, char *fname, int nx, int ny)
{
	ofstream fout;

	//cout << "Writing " << nx << "x" << ny << " image." << endl;

	fout.open(fname, ios::binary);
	if (fout == NULL) {
		cout << "File I/O error" << endl;
		return(0);
	}

	fout << "P6" << endl;
	fout << "# Intermediate image file" << endl;
	fout << nx << " " << ny << endl;
	fout << "255" << endl ;


    fout.write((const char *)image, 3 * nx * ny * sizeof(unsigned char));
	fout.close();
	return 1;
}

/*
// Philippos 9/30/02
unsigned char *read_ppm_image(char *fname, int *nx, int *ny)
{
	unsigned char *dummy;
	int i_size, x, y, s;
	//char in_c[2];
	ifstream fin;

	fin.open(fname, ios::binary);
	if (fin == NULL){
		cout << "File I/O error" << endl;
		exit(0);
	}


	char line[110];
	fin.getline(line,100); //read P#

	fin.getline(line, 5, ' ');

	if(line[0] >= '0' && line[0] <= '9')  // read number
		x = atoi(line);
	else
	{
		fin.getline(line, 100);  // read through comment
		fin >> x;
	}

	fin >> y >> s; // >> t;
	cout << "x " << x << " y " << y << endl;
	cout << "s " << s << endl; // " t " << t << endl;
	while('\n'==fin.peek())
		fin.ignore(1);


//	fin.getline(line,100); //read comments (now they become necessary)
//	fin >> x >> y >> s; // >> t;     // these two lines require comment

	cout << "x " << x << " y " << y << endl;
	cout << "s " << s << endl; // " t " << t << endl;
	while('\n'==fin.peek())
		fin.ignore(1);
	*nx=x; *ny=y;
	i_size=(*nx)*(*ny)*3;

	dummy = (unsigned char *) malloc((unsigned)i_size*sizeof(char));
	fin.read((char *)dummy, i_size);
	fin.close();
	return(dummy);
}

*/

void ppm2rgb( unsigned char *image, unsigned char** red, unsigned char** green, unsigned char** blue,
			 int width, int height)
{
	int i, j, pt=0;

	for( j=0; j<height; j++)
		for( i=0; i<width; i++)
		{
			red[i][j] = image[pt];
			pt++;
			green[i][j] = image[pt];
			pt++;
			blue[i][j] = image[pt];
			pt++;
		}

}









