#pragma once
#define MAX 100

#include<iostream>
#include<string>
using namespace std;

struct Person
{
	string Name;
	int Sex;
	int Age;
	string Number;
	string Address;
};

struct AddressBook
{
	struct Person P_Arr[MAX];
	int B_size;
};


#ifndef sub_h
#define sub_h
void menu();
int Select();
int Search(AddressBook* book);
void add(AddressBook* book);
void Showall(AddressBook* book);
void Addperson(AddressBook* book);
void Showperson(AddressBook* book);
void Deleteperson(AddressBook* book);
void Checkperson(AddressBook* book);
void Modifyperson(AddressBook* book);
void Clearperson(AddressBook* book);
#endif
