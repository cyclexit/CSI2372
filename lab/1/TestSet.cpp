#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set A, B, C, D, E, F, G, H;

	A.add_element(1);
	A.add_element(2);
	A.add_element(5);
	A.add_element(9);
	A.add_element(10);

	B.add_element(1);
	B.add_element(4);
	B.add_element(5);
	B.add_element(8);

	C.add_element(2);
	C.add_element(4);
	C.add_element(5);
	C.add_element(8);
	C.add_element(10);

	//Testing Cardinality
	if (A.cardinality() == 5) cout << "Cardinality - Test 1 - Passed." << endl;
	else cout << "Cardinality - Test 1 - Failed!" << endl;

	if (B.cardinality() == 4) cout << "Cardinality - Test 2 - Passed." << endl;
	else cout << "Cardinality - Test 2 - Failed!" << endl;

	if (D.cardinality() == 0) cout << "Cardinality - Test 3 - Passed." << endl;
	else cout << "Cardinality - Test 3 - Failed!" << endl;

	//Testing is_member
	if (A.is_member(1)) cout << "is_member - Test 1 - Passed." << endl;
	else cout << "is_member - Test 1 - Failed!" << endl;

	if (!A.is_member(3)) cout << "is_member - Test 2 - Passed." << endl;
	else cout << "is_member - Test 2 - Failed!" << endl;

	if (!D.is_member(2)) cout << "is_member - Test 3 - Passed." << endl;
	else cout << "is_member - Test 3 - Failed!" << endl;

	if (B.is_member(8)) cout << "is_member - Test 4 - Passed." << endl;
	else cout << "is_member - Test 4 - Failed!" << endl;


	//Testing add_element
	A.add_element(3);
	if (A.is_member(3)) cout << "add_element - Test 1 - Passed." << endl;
	else cout << "add_element - Test 1 - Failed!" << endl;

	D.add_element(10);
	if (D.is_member(10)) cout << "add_element - Test 2 - Passed." << endl;
	else cout << "add_element - Test 2 - Failed!" << endl;

	B.add_element(4);
	if (B.is_member(4)) cout << "add_element - Test 3 - Passed." << endl;
	else cout << "add_element - Test 3 - Failed!" << endl;

	//Testing remove_element
	A.remove_element(3);
	if (!A.is_member(3)) cout << "remove_element - Test 1 - Passed." << endl;
	else cout << "add_element - Test 1 - Failed!" << endl;

	D.remove_element(10);
	if (!D.is_member(10)) cout << "remove_element - Test 2 - Passed." << endl;
	else cout << "add_element - Test 2 - Failed!" << endl;

	B.remove_element(4);
	if (!B.is_member(4)) cout << "remove_element - Test 3 - Passed." << endl;
	else cout << "add_element - Test 3 - Failed!" << endl;

	//Testing subset
	if (D.subset(A)) cout << "subset - Test 1 - Passed." << endl;
	else cout << "subset - Test 1 - Failed!" << endl;

	D.add_element(2);
	D.add_element(5);
	D.add_element(10);

	if (D.subset(A)) cout << "subset - Test 2 - Passed." << endl;
	else cout << "subset - Test 2 - Failed!" << endl;

	D.add_element(6);
	if (!D.subset(A)) cout << "subset - Test 3 - Passed." << endl;
	else cout << "subset - Test 3 - Failed!" << endl;

	if (!B.subset(A)) cout << "subset - Test 4 - Passed." << endl;
	else cout << "subset - Test 4 - Failed!" << endl;

	//Testing equal
	D.remove_element(6);
	if (!D.equal(A)) cout << "equal - Test 1 - Passed." << endl;
	else cout << "equal - Test 1 - Failed!" << endl;

	if (!A.equal(D)) cout << "equal - Test 2 - Passed." << endl;
	else cout << "equal - Test 2 - Failed!" << endl;

	D.add_element(1);
	D.add_element(9);
	
	if (D.equal(A)) cout << "equal - Test 3 - Passed." << endl;
	else cout << "equal - Test 3 - Failed!" << endl;

	//Testing Union
	if (A.equal(A.Union(E))) cout << "Union - Test 1 - Passed." << endl;
	else cout << "Union - Test 1 - Failed!" << endl;

	E.add_element(1);
	E.add_element(2);
	E.add_element(4);
	E.add_element(5);
	E.add_element(8);
	E.add_element(9);
	E.add_element(10);

	if (E.equal(A.Union(C))) cout << "Union - Test 2 - Passed." << endl;
	else cout << "Union - Test 2 - Failed!" << endl;

	if (B.equal(F.Union(B))) cout << "Union - Test 3 - Passed." << endl;
	else cout << "Union - Test 3 - Failed!" << endl;

	if (!E.equal(B.Union(C))) cout << "Union - Test 4 - Passed." << endl;
	else cout << "Union - Test 4 - Failed!" << endl;

	//Testing intersection
	if (F.equal(F.intersection(A))) cout << "intersection - Test 1 - Passed." << endl;
	else cout << "intersection - Test 1 - Failed!" << endl;

	F.add_element(1);
	F.add_element(5);
	if (F.equal(A.intersection(B))) cout << "intersection - Test 2 - Passed." << endl;
	else cout << "intersection - Test 2 - Failed!" << endl;

	if (!F.equal(A.intersection(C))) cout << "intersection - Test 3 - Passed." << endl;
	else cout << "intersection - Test 3 - Failed!" << endl;

	//Testing difference
	if (A.equal(A.difference(G))) cout << "difference - Test 1 - Passed." << endl;
	else cout << "difference - Test 1 - Failed!" << endl;

	if (G.equal(G.difference(A))) cout << "difference - Test 2 - Passed." << endl;
	else cout << "difference - Test 2 - Failed!" << endl;

	G.add_element(2);
	G.add_element(9);
	G.add_element(10);
	if (G.equal(A.difference(B))) cout << "difference - Test 3 - Passed." << endl;
	else cout << "difference - Test 3 - Failed!" << endl;

	//Testing mutual_difference
	if (A.equal(A.mutual_difference(H))) cout << "mutual_difference - Test 1 - Passed." << endl;
	else cout << "mutual_difference - Test 1 - Failed!" << endl;

	if (A.equal(H.mutual_difference(A))) cout << "mutual_difference - Test 2 - Passed." << endl;
	else cout << "mutual_difference - Test 2 - Failed!" << endl;

	H.add_element(2);
	H.add_element(8);
	H.add_element(9);
	H.add_element(10);

	if (H.equal(A.mutual_difference(B))) cout << "mutual_difference - Test 3 - Passed." << endl;
	else cout << "mutual_difference - Test 3 - Failed!" << endl;

	if (H.equal(B.mutual_difference(A))) cout << "mutual_difference - Test 4 - Passed." << endl;
	else cout << "mutual_difference - Test 4 - Failed!" << endl;

	if (!H.equal(A.mutual_difference(C))) cout << "mutual_difference - Test 5 - Passed." << endl;
	else cout << "mutual_difference - Test 5 - Failed!" << endl;

	return 0;
}