// lookuptable.cpp

// ENSF 480 - Lab 2 - Exercise A
 
// Completed by: Quentin Jennings - 30089570

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"

using namespace std;

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

const Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const Mystring& datumA)
{
  // Add new node at head?                                                                                  
  if (headM == 0 || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }
	
  // Overwrite datum at head?                                                                               
  else if (keyA == headM->keyM)
    headM->datumM = datumA;
	
  // Have to search ...                                                                                     
  else {
      
    //POINT ONE
		
    // if key is found in list, just overwrite data;                                                        
    for (Node *p = headM; p !=0; p = p->nextM)
		{
			if(keyA == p->keyM)
			{
				p->datumM = datumA;
				return;
			}
		}
		
    //OK, find place to insert new node ...                                                                 
    Node *p = headM ->nextM;
    Node *prev = headM;
		
    while(p !=0 && keyA >p->keyM)
		{
			prev = p;
			p = p->nextM;
		}
		
    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
	
}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    } 
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}


// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.

void DictionaryList::find(const Key& keyA)
{
  //sets cursorM to the start of the linked list
  go_to_first();

  //if the list is empty or the key is at the start, no work is needed
  if(cursor_ok() && sizeM > 0) {
    if(headM -> keyM != keyA) {
      //as long as we haven't reached the end of the list:
      while(cursorM != 0) {
        //if we haven't found the key yet, go forward.
        if(cursor_key() == keyA)
          break;
        else
          step_fwd();
      }
    }
  }
}


void DictionaryList::destroy()
{
  go_to_first();

  if(headM != 0 && sizeM > 0) {
    Node* tempCursor;
    while(cursor_ok()) {
      tempCursor = cursorM;
      step_fwd();
      delete tempCursor;
    }
  }
  headM = cursorM = 0;
  sizeM = 0;
}


void DictionaryList::copy(const DictionaryList& source)
{
  headM = cursorM = 0;
  sizeM = 0;

  if(source.size() > 0) {
    Node* sourceCursor = source.headM;

    while(sourceCursor != 0) {
      insert(sourceCursor -> keyM, sourceCursor -> datumM);
      sourceCursor = sourceCursor -> nextM;
    }

    if(source.cursor_ok()){
      sourceCursor = source.headM;
      cursorM = headM;
      while(cursor_ok() && sourceCursor != 0) {
        if(cursor_key() == source.cursorM -> keyM) {
          break;
        }
        else {
          step_fwd();
          sourceCursor = sourceCursor -> nextM;
        }
      }
    }
  }
}

