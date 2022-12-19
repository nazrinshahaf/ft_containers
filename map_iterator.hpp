#ifndef MAP_ITERATOR
# define MAP_ITERATOR

#include "iterator.hpp"
#include "colours.h"

/*
 * Underlying iterator for map.
 *
 * Based of bidirectional iterator.
 *
 * @edit : remove node from namespace.
 * */

# define RBT_BLACK false
# define RBT_RED true

template <class T>
struct Node
{
	typedef	Node<T>		*node_ptr;

	Node() :
		data(),
		parent(nullptr),
		left(nullptr),
		right(nullptr),
		colour(false)
	{ cout << GREEN "Node Default Constructor Called" RESET << endl; }

	Node(T val, node_ptr parent = nullptr, node_ptr left = nullptr,
			node_ptr right = nullptr, bool colour = false) :
		data(val),
		parent(parent),
		left(left),
		right(right),
		colour(colour)
	{ cout << GREEN "Node Fill Constructor Called" RESET << endl; }

	~Node() { cout << RED "Node Destructor Called" RESET << endl; }

	T			data;
	node_ptr	parent;
	node_ptr	left;
	node_ptr	right;
	bool		colour;
};

template <class T>
class	RedBlackTree
{
	typedef	T			value_type;
	typedef	Node<T>		node;
	typedef	Node<T>		*node_ptr;

	public:

		/*
		 * default constructor.
		 * default destructor.
		 * */

		RedBlackTree()
		{
			cout << GREEN "RedBlackTree default consturctor called" RESET << endl;
			_sentinal = new node();
			_sentinal->parent = _sentinal;
			_sentinal->left = _sentinal;
			_sentinal->right = _sentinal;
			_root = _sentinal;
		}

		~RedBlackTree()
		{
			cout << RED "RedBlackTree destructor called" RESET << endl;
			delete_tree(_root);
			delete _sentinal;
		}

		/*
		 * insert.
		 *
		 * Always insert as a red as red doesnt violate any properties of the rbt.
		 *
		 * Insert for a red black tree is just inserts the new value as a red
		 * node and follows the binary search tree insertion rule. 
		 * If val < node.data keep going left.
		 *
		 * After insertion do fixup.
		 *
		 * @param 'val' : the value to be inserted into the binary tree.
		 * */

		void	insert_node(value_type val)
		{
			//if tree has no elements
			if (_root == _sentinal)
			{
				_root = new node(val, _sentinal, _sentinal, _sentinal, RBT_BLACK);
				//_sentinal->right = _root;
				//_sentinal->left = _root;
				return ;
			}

			//if the tree has one element
			//if (_sentinal->right == _sentinal->left)
			//{
			//	if (val > _root->data)
			//	{
			//		_root->right = new node(val, _root, _sentinal, _sentinal, RBT_RED);
			//		//_sentinal->right = _root->right;
			//	}
			//	else
			//	{
			//		_root->left = new node(val, _root, _sentinal, _sentinal, RBT_RED);
			//		//_sentinal->left = _root->left;
			//	}
			//	return ;
			//}

			//normal insert
			node_ptr	front = _root;
			node_ptr	back = _root;
			while (front != _sentinal)
			{
				back = front;
				if (val < front->data)
					front = front->left;
				else
					front = front->right;
			}

			node_ptr	insert = new node(val, back, _sentinal, _sentinal, RBT_RED);
			if (back->data > insert->data)
				back->left = insert;
			else
				back->right = insert;

			//if (insert->data < _sentinal->left->data)
			//	_sentinal->left = insert;
			//if (insert->data > _sentinal->right->data)
			//	_sentinal->right = insert;

			//print_helper(_root, "", true);
			insert_fixup(insert);
		}

		/*
		 * delete_node.
		 *
		 * Deleting a node from a red black tree follows the same logic
		 * as deleting a node from a binary search tree. After the deletion
		 * a fixup will be applied.
		 *
		 * case 1
		 * if (z.left is NILL)
		 * 	-> x = z.right
		 * 	-> transplant(z,x)
		 * 	-> delete_fixup(x);
		 * 
		 * case 2
		 * if (z.right is NILL)
		 * 	-> x = z.left
		 * 	-> transplant(z,x)
		 * 	-> delete_fixup(x);
		 * 
		 * case 3
		 * if (z has 2 children)
		 * 	-> y = minimum in z right child subtree (inorder traversal)
		 * 	-> x = y.right
		 * 	if (y.parent is z)
		 * 		-> x.parent = y *
		 * 	else (y.parent is not z)
		 * 		-> transplant(y, x) **
		 * 		-> x = z.right
		 * 		-> x.parent = y
		 * 		-> y.right = x;
		 * 	-> transplant(z, y)
		 * 	-> y.left = z.left;
		 * 	-> y.left.parent = y;
		 * 	-> y.colour = z.colour
		 * 	-> delete_fixup(x)
		 *
		 * 	* This specific case must modify the parent of the sentinal node
		 *  to attempt the fix. This means the _sentinal check in transplant
		 *  must also be removed to fulfill the needs of this tree.
		 * 	
		 * 	** cannot modify the value of x in this scenario, it will attempt to
		 * 	rebalance even though the tree is balanced.
		 * */

		void	delete_node(value_type val)
		{
			node_ptr	z = search_tree(_root, val);
			node_ptr	y = z;
			node_ptr	x;
			bool		original_colour = y->colour;

			if (z == _sentinal)
				return ;
			//cout << "z : " << z->data << endl;
			//cout << "z addr: " << z << endl;
			if (z->left == _sentinal) //case 1
			{
				x = z->right;
				//cout << "x : " << x->data << endl;
				transplant(z, x);
				//cout << "case 1" << endl;
				//print_helper(_root, "", true);
			}
			else if (z->right == _sentinal) //case 2
			{
				x = z->left;
				//cout << "x : " << x->data << endl;
				transplant(z, x);
			}
			else //case 3
			{
				y = minimum_in_subtree(z->right);
				x = y->right;
				//cout << "y here: " << y->data << endl;
				//cout << "x here: " << x->data << endl;
				original_colour = y->colour;
				if (y->parent == z)
					x->parent = y; //*
				else 
				{
					transplant(y, y->right); //**
					//cout << GREEN "AFTER FIRST TRANSPLANT" RESET << endl;
					//print_helper(_root, "", true);
					//x = z->right;
					//x->parent = y;
					//y->right = x;
					y->right = z->right;
					y->right->parent = y;
					//print_helper(_root, "", true);
				}
				//print_helper(_root, "", true);
				//cout << "before transplant" << endl;
				//cout << "z : " << z->data << endl;
				//cout << "y : " << y->data << endl;
				//cout << "y : " << y->right->data << endl;
				//cout << "x : " << x->data << endl;
				transplant(z, y);
				//cout << GREEN "AFTER SECOND TRANSPLANT" RESET << endl;
				//print_helper(_root, "", true);
				y->left = z->left;
				y->left->parent = y;
				y->colour = z->colour;
			}
			delete z;
			//cout << (original_colour == RBT_BLACK ? "BLACK" : "RED") << endl;
			if (original_colour == RBT_BLACK)
				delete_fixup(x);
		}

		/*
		 * print_helper.
		 * */

		void	print_helper(node_ptr n, std::string indent, bool last)
		{
			if (n != _sentinal)
			{
				cout << indent;
				if (last)
				{
					cout << "R----";
					indent += "     ";
				}
				else
				{
					cout << "L----";
					indent += "|    ";
				}
				cout << n->data << (n->colour == RBT_BLACK ? RED : GREEN)
					<< "(" << (n->colour == RBT_BLACK ? "B" : "R")
					<< ")" RESET << endl;
				print_helper(n->left, indent, false);
				print_helper(n->right, indent, true);
			}
		}

		/*
		 * get_root.
		 *
		 * Returns root of tree.
		 * */

		node_ptr	get_root(void)
		{
			return (this->_root);
		}

	private:

		/*
		 * Helper function for rbt destructor.
		 * */

		void delete_tree(node_ptr node)
		{
			if (node != _sentinal)
			{
				delete_tree(node->left);
				delete_tree(node->right);
				delete node;
			}
		}

		void	inorder_traversal(node_ptr node)
		{
			if (node != _sentinal)
			{
				inorder_traversal(node->left);

				if (node->colour == RBT_BLACK)
					cout << RED; //idk why my red is black
				else if (node->colour == RBT_RED)
					cout << GREEN; //idk why green is red
				cout << node->data << RESET << endl;

				inorder_traversal(node->right);
			}
		}

		void	postorder_traversal(node_ptr node)
		{
			if (node != _sentinal)
			{
				postorder_traversal(node->left);
				postorder_traversal(node->right);

				if (node->colour == RBT_BLACK)
					cout << RED; //idk why my red is black
				else if (node->colour == RBT_RED)
					cout << GREEN; //idk why green is red
				cout << node->data << RESET << endl;
			}
		}

		void	preorder_traversal(node_ptr node)
		{
			if (node != _sentinal)
			{
				if (node->colour == RBT_BLACK)
					cout << RED; //idk why my red is black
				else if (node->colour == RBT_RED)
					cout << GREEN; //idk why green is red
				cout << node->data << RESET << endl;

				preorder_traversal(node->left);
				preorder_traversal(node->right);
			}
		}

		node_ptr	search_tree(node_ptr node, value_type to_find)
		{
			if (node == _sentinal || node->data == to_find)
				return node;
			if (to_find < node->data)
				return search_tree(node->left, to_find);
			else
				return search_tree(node->right, to_find);
		}

		/*
		 * get_sibling.
		 *
		 * Returns the sibling of node x.
		 *
		 * @param 'x' : the value to get the sibling of.
		 * */

		node_ptr	get_sibling(node_ptr x)
		{
			if (x->parent == _sentinal)
				return (_sentinal);
			if (x->parent->left == x)
				return x->parent->right;
			else
				return x->parent->left;
		}

		/*
		 * transplant.
		 *
		 * Transplant replaces one subtree with as a child
		 * of its parent with another subtree. Essentially
		 * swapping their child components.
		 *
		 * if x is root
		 * 		new root = y
		 * else if x is a left child
		 * 		y = new parent left subtree
		 * 		(replace x as the //new parent left subtree)
		 * else if x is right child
		 * 		y is the right subtree of its parent.
		 *
		 * @param 'x' : the node to transplant.
		 * @param 'y' : the node to transplant with.
		 * */

		void	transplant(node_ptr x, node_ptr y)
		{
			if (x->parent == _sentinal)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			//if (y != _sentinal)
			y->parent = x->parent;
		}

		/*
		 * left_rotate.
		 * right_rotate.
		 *
		 * Rotation in binary tree means to 'rotate'
		 * the contents of the tree without intefering
		 * with the order.
		 *
		 * https://www.youtube.com/watch?v=dCF_d-zc_bQ
		 *
		 * to rorate on x means basically means make y
		 * the new root and make x a subtree of y. All
		 * of this is done without intefering with the
		 * order of tree.
		 *
		 * @param 'x' : the node to perform a rotation on.
		 * */

		void	left_rotate(node_ptr x)
		{
			node_ptr y = x->right;
			node_ptr b = y->left;
			transplant(x, y);
			x->right = b;
			if (b != _sentinal)
				b->parent = x;
			y->left = x;
			x->parent = y;
		}

		void	right_rotate(node_ptr x)
		{
			node_ptr y = x->left;
			node_ptr b = y->right;
			transplant(x, y);
			x->left = b;
			if (b != _sentinal)
				b->parent = x;
			y->right = x;
			x->parent = y;
		}

		/*
		 * minimum_in_subtree.
		 *
		 * Returns the minimum value in subtree of 'n'
		 *
		 * @param 'n' : the parent to search the subtree for
		 * 	the minimum value.
		 * */

		node_ptr	minimum_in_subtree(node_ptr n)
		{
			while (n->left != _sentinal)
				n = n->left;
			return (n);
		}

		/*
		 * maximum_in_subtree.
		 *
		 * Returns the maximum value in subtree of 'n'.
		 *
		 * @param 'n' : the parent to search the subtree for
		 * 	the maximum value.
		 * */

		node_ptr	maximum_in_subtree(node_ptr n)
		{
			while (n->right != _sentinal)
				n = n->right;
			return (n);
		}

		/*
		 * insert_fixup.
		 *
		 * There are 3 cases for isnert_fixup. The fixup code has been
		 * made in a way that the fix has to cascade its way up the tree.
		 *
		 * case 1
		 * if (z.parent and z.uncle are red)
		 * 	-> colour z.parent black
		 * 	-> colour z.uncle black
		 * 	-> colour z.gp red
		 * 	-> repeat on z.gp
		 *
		 * case 2
		 * if z.parent is red and z.uncle is black
		 * if z is right child and z.parent is left child
		 * (z and parent have to be opposite child if not refer to case 2)
		 * if (z is right child and z.parent is left child)
		 * 	-> z = z.parent
		 * 	-> left rotate on z.parent
		 * if (z is left child and z.parent is right child)
		 * 	-> z = z.parent
		 * 	-> right rotate on z.parent
		 *
		 * case 3
		 * if z.parent is red and z.uncle is black
		 * if z and z.parent are both left/right child
		 * (both z and parent have to be left left or right right)
		 * if (z and z.parent are both left child)
		 * 	-> right rotate on z.gp
		 * 	-> colour z.parent black
		 * 	-> colour z.sibling red
		 * if (z and z.parent are both right child)
		 * 	-> left rotate on z.gp
		 * 	-> colour z.parent black
		 * 	-> colour z.sibling red
		 *
		 * @param 'z' : node to run fixup on.
		 * */

		void	insert_fixup(node_ptr z)
		{
			while (z->parent->colour == RBT_RED && z != _root)
			{
				node_ptr	par = z->parent;
				node_ptr	gp = par->parent;
				node_ptr	unc = get_sibling(par);
				if (par == gp->left) //if parent is left child
				{
					if (unc->colour == RBT_RED) //if uncle is red
					{
						//cout << "entered case 1 top loop" << endl;
						par->colour = RBT_BLACK;
						unc->colour = RBT_BLACK;
						gp->colour = RBT_RED;
						z = gp;
					}
					else //if uncle is black (case 2 or case 3)
					{
						if (z == par->right) //child is right and parent is left (case 2)
						{
							//cout << "entered case 2 top loop" << endl;
							z = par; //if sentinal check
							left_rotate(z);
							par = z->parent;
							gp = par->parent;
							unc = get_sibling(par);
						}
						//cout << "entered case 3 top loop" << endl;
						par->colour = RBT_BLACK;
						gp->colour = RBT_RED;
						right_rotate(gp);
					}
				}
				else //if parent is right child
				{
					if (unc->colour == RBT_RED) //if uncle is red
					{
						//cout << "entered case 1 bottom loop" << endl;
						par->colour = RBT_BLACK;
						unc->colour = RBT_BLACK;
						gp->colour = RBT_RED;
						z = gp;
					}
					else //if uncle is black (case 2 or case 3)
					{
						if (z == par->left) //child is left and parent is right (case 2)
						{
							//cout << "entered case 2 bottom loop" << endl;
							z = par;
							right_rotate(z);
							par = z->parent;
							gp = par->parent;
							unc = get_sibling(par);
						}
						//cout << "entered case 3 bottom loop" << endl;
						par->colour = RBT_BLACK;
						gp->colour = RBT_RED;
						left_rotate(gp);
					}
				}
				//print_helper(_root, "", true);
			}
			_root->colour = RBT_BLACK;
		}

		/*
		 * delete_fixup.
		 * 
		 * delete_fixup may not be complete and may call other fixups.
		 * So after a case fixup the RBT may still be broken. Just like
		 * insert_fixup it will cascade its way up till the top of the tree.
		 * 
		 * w = x.sibling
		 * 
		 * case 1
		 * if (w is red)
		 * 	-> colour w to black
		 * 	-> colour x.parent colour to red
		 * 	if (x is left child)
		 * 		-> left_rotate(x.parent)
		 * 	else if (x is right child)
		 * 		-> right_rotate(x.parent)
		 * 	-> w = x.parent.right
		 * 
		 * case 2
		 * if (w and w.left and w.right is black)
		 * 	-> colour w to red
		 * 	-> x = x.parent
		 * 
		 * case 3
		 * if (w is black, w.left is red and w.right is black)
		 * 	if (x is left child)
		 * 		-> colour w.left to black
		 * 		-> colour w to red
		 * 		-> right_rotate(w)
		 * 		-> w = x.parent.right
		 * 		-> case 4
		 * 	else if (x is right child)
		 * 		-> mirror ^
		 * 
		 * case 4
		 * if (w is black and w.right is red)
		 * 		-> colour w to x.parent.colour
		 * 		-> colour x.parent to black
		 * 		-> colour w.right to black
		 * 	if (x is left child)
		 * 		-> left_rotate(x.parent)
		 * 	else if (x is right child)
		 * 		-> right_rotate(x.parent)
		 * 		-> set x to root
		 */

		void	delete_fixup(node_ptr x)
		{
			//cout << "fixup on x : " << x->data << endl;
			//cout << "-------------" << endl;
			//print_helper(_root, "", true);
			//cout << "-------------" << endl;
			//if (x == _sentinal)
			//	cout << "to fix is sentinal" << endl;
			while (x != _root && x->colour == RBT_BLACK)
			{
				//cout << GREEN "ENTERED LOOP" RESET << endl;
				print_helper(_root, "", true);
				if (x == x->parent->left) //if x is left child
				{
					node_ptr	w = get_sibling(x);
					if (w->colour == RBT_RED) //case 1
					{
						//cout << "UP CASE 1" << endl;
						w->colour = RBT_BLACK;
						x->parent->colour = RBT_RED;
						left_rotate(x->parent);
						w = x->parent->right;
					}
					if (w->left->colour == RBT_BLACK &&
							w->right->colour == RBT_BLACK) //case 2
					{
						//cout << "UP CASE 2" << endl;
						w->colour = RBT_RED;
						x = x->parent;
					}
					else //case 3 and case 4
					{
						if (w->right->colour == RBT_BLACK) //case 3
						{
							w->left->colour = RBT_BLACK;
							//cout << "UP CASE 3" << endl;
							w->colour = RBT_RED;
							right_rotate(w);
							w = x->parent->right;
						}
						//cout << "UP CASE 4" << endl;
						w->colour = x->parent->colour;
						x->parent->colour = RBT_BLACK;
						w->right->colour = RBT_BLACK;
						left_rotate(x->parent);
						x = _root;
					}
				}
				else //if x is right child
				{
					node_ptr	w = get_sibling(x);
					if (w->colour == RBT_RED)
					{
						//cout << "DOWN CASE 1" << endl;
						w->colour = RBT_BLACK;
						x->parent->colour = RBT_RED;
						right_rotate(x->parent);
						w = x->parent->left;
					}
					if (w->left->colour == RBT_BLACK &&
							w->right->colour == RBT_BLACK) //case 2
					{
						//cout << "DOWN CASE 2" << endl;
						w->colour = RBT_RED;
						x = x->parent;
					}
					else
					{
						if (w->left->colour == RBT_BLACK)
						{
							//cout << "DOWN CASE 3" << endl;
							w->right->colour = RBT_BLACK;
							w->colour = RBT_RED;
							left_rotate(w);
							w = x->parent->left;
						}
						//cout << "DOWN CASE 4" << endl;
						w->colour = x->parent->colour;
						x->parent->colour = RBT_BLACK;
						w->left->colour = RBT_BLACK;
						right_rotate(x->parent);
	  					x = _root;
					}
				}
				//cout << "LOOP END" << endl;
				//print_helper(_root, "", true);
			}
			x->colour = RBT_BLACK;
			_sentinal->parent = _sentinal;
			_sentinal->right = _sentinal;
			_sentinal->left = _sentinal;
			//cout << "EXIT LOOP" << endl;
			//print_helper(_root, "", true);
			//cout << endl << endl << endl;
		}

		node_ptr	_sentinal;
		node_ptr	_root;
};

namespace ft
{
	template <class	T>
	struct	map_iterator : public ft::iterator<ft::map_iterator_tag, T>
	{
		typedef	T	value_type;
		typedef	typename ft::iterator<ft::map_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::map_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::iterator<ft::map_iterator_tag, T>::pointer				pointer;
		typedef typename ft::iterator<ft::map_iterator_tag, T>::reference			reference;
	};
}

#endif
