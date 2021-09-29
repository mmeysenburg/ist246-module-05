#include <climits>
#include <iostream>
#include "SimpleSLL.h"

//-----------------------------------------------------------
// function implementations
//-----------------------------------------------------------

/*
 * Delete all list nodes when the list is destroyed.
 */
SimpleSLL::~SimpleSLL() { clear(); }

/*
 * Add i to front of list.
 */
void SimpleSLL::add(int i) {
  // create new node
  SimpleSLL::Node *pT = new SimpleSLL::Node(i, pHead);
  // change head to point to new node
  pHead = pT;
  // increment size
  n++;
}

/*
 * Delete all list nodes.
 */
void SimpleSLL::clear() {
  // create cursors
  SimpleSLL::Node *pCurr = pHead, *pPrev = 0;

  // iterate through the list
  while (pCurr != 0) {
    // "inchworm" up to next node
    pPrev = pCurr;
    pCurr = pCurr->pNext;

    // delete previous node
    delete pPrev;
  }

  // reset head pointer and size
  pHead = 0;
  n = 0u;
}

/*
 * Search the list for integer i.
 */
int SimpleSLL::contains(int i) const {
  // create cursors
  int idx = -1;
  SimpleSLL::Node *pCurr = pHead;

  // iterate until we find i or end of list
  while (pCurr != 0) {
    idx++;
    // hit? return index
    if (pCurr->data == i) {
      return idx;
    }

    pCurr = pCurr->pNext;
  }

  // not found
  return -1;
}

/*
 * Get value at location idx.
 */
int SimpleSLL::get(unsigned idx) const {
  // initialize cursor
  SimpleSLL::Node *pCurr = pHead;

  // if the access is past list end, throw an exception
  if (idx >= n) {
    throw std::out_of_range("Index out of range in SimpleSLL::get()");
  }

  // iterate cursor to postion
  for (unsigned i = 0u; i < idx && pCurr != 0; i++) {
    pCurr = pCurr->pNext;
  }

  // return requested value
  return pCurr->data;
}

/*
 * Remove node at location idx.
 */
int SimpleSLL::remove(unsigned idx) {
  // initialize cursors
  SimpleSLL::Node *pCurr = pHead, *pPrev = 0;

  // if the access is past list end, throw an exception
  if (idx >= n) {
    throw std::out_of_range("Index out of range in SimpleSLL::remove()");
  }

  // iterate cursors to position
  for (unsigned i = 0u; i < idx && pCurr != 0; i++) {
    pPrev = pCurr;
    pCurr = pCurr->pNext;
  }

  // save value of node we're deleting
  int d = pCurr->data;

  // first element? change head pointer
  if (pCurr == pHead) {
    pHead = pCurr->pNext;
  } else {
    // general case: "wire around" node
    pPrev->pNext = pCurr->pNext;
  }

  // remove node and decrement size
  delete pCurr;
  n--;

  // send return value
  return d;
}

/*
 * Print the list to standard output
 */
void SimpleSLL::print() const {
  using namespace std;

  cout << "[";

  // call recursive helper method
  print(pHead);

  cout << "]" << endl;
}

/*
 * Recursive helper for print().
 */
void SimpleSLL::print(const SimpleSLL::Node *pCurr) const {
  using namespace std;

  // base case: is there more to print?
  if (pCurr != 0) {
    cout << pCurr->data;

    // no comma for last node
    if (pCurr->pNext != 0) {
      cout << ", ";
    }

    // recurse
    print(pCurr->pNext);
  }
}

/*
 * Change the value at location idx to i.
 */
void SimpleSLL::set(unsigned idx, int i) {
  // initialize cursor
  SimpleSLL::Node *pCurr = pHead;

  // if the access is past list end, throw an exception
  if (idx >= n) {
    throw std::out_of_range("Index out of range in SimpleSLL::set()");
  }

  // iterate to location
  for (unsigned j = 0u; j < idx; j++) {
    pCurr = pCurr->pNext;
  }

  // change data in location idx to i
  pCurr->data = i;
}
