//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */
 
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <memory>
// #include "BinaryTreeInterface.h"
#include "BinaryNode.hpp"
// #include "BinaryNodeTree.h"
// #include "NotFoundException.h"
// #include "PrecondViolatedExcep.h"

template<class T>
class BinarySearchTree
{
private:
   std::shared_ptr<BinaryNode<T>> rootPtr;
   
protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------
   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
  auto placeNode(std::shared_ptr<BinaryNode<T>> subTreePtr,
                                       std::shared_ptr<BinaryNode<T>> newNode);
   
   // Removes the given target value from the tree while maintaining a
   // binary search tree.
   std::shared_ptr<BinaryNode<T>> removeValue(std::shared_ptr<BinaryNode<T>> subTreePtr,
                                     const T target,
                                     bool& success);
   
   // Removes a given node from a tree while maintaining a
   // binary search tree.
   auto removeNode(std::shared_ptr<BinaryNode<T>> nodePtr);
   
   // Removes the leftmost node in the left subtree of the node
   // pointed to by nodePtr.
   // Sets inorderSuccessor to the value in this node.
   // Returns a pointer to the revised subtree.
   auto removeLeftmostNode(std::shared_ptr<BinaryNode<T>> subTreePtr,
                                            T& inorderSuccessor);
   
   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   auto findNode(std::shared_ptr<BinaryNode<T>> treePtr,
                                  const T& target) const;

   // Recursively deletes all nodes from the tree.
   void destroyTree(std::shared_ptr<BinaryNode<T>> subTreePtr);
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   BinarySearchTree(const T& rootItem);
   BinarySearchTree(const BinarySearchTree<T>& tree);
   virtual ~BinarySearchTree();
   
   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------

   std::shared_ptr<BinaryNode<T>> getRoot() const;
   bool isEmpty() const ;
   int getHeight() const ;
   int getNumberOfNodes() const ;
   bool add(const T& newEntry) ;
   bool remove(const T& anEntry) ;
   void clear() ;
   bool contains(const T& anEntry) const ;

   std::shared_ptr<BinaryNode<T>> getPointerTo(const T& target) const;
   
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse(void visit(T&)) const ;
   void inorderTraverse(void visit(T&)) const ;
   void postorderTraverse(void visit(T&)) const ;

   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinarySearchTree<T>& operator=(const BinarySearchTree<T>& rightHandSide);   
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif
