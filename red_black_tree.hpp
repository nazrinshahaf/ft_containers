#ifndef RED_BLACK_TREE
# define RED_BLACK_TREE

#include "map_iterator.hpp"
#include "iterator.hpp"

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class	RedBlackTree
{
	public:
		typedef	T													value_type;
		typedef	Node<T>												node;
		//typedef	Node<T>												*node_ptr;
		typedef	Compare												key_compare;
		typedef	Alloc												allocator_type;
		typedef	typename Alloc::template rebind<Node<T> >::other	node_allocator;
		typedef	typename node_allocator::pointer					node_pointer;
		typedef typename allocator_type::pointer					pointer;
		//typedef typename allocator_type::const_pointer				const_pointer;
		typedef ft::map_iterator<value_type>						iterator;
		typedef ft::map_iterator<const value_type>					const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef std::size_t											size_type;

	private:
		allocator_type	_val_alloc;
		node_allocator	_node_alloc;
		node_pointer	_sentinal;
		node_pointer	_root;
		key_compare		_compare;
		size_type		_size;

	public:

		/*
		 * default constructor.
		 *
		 * @note : Node constructor will call twice when 
		 * 	_node_alloc.construct is called.
		 * */

		RedBlackTree(const key_compare comp = key_compare(),
				const allocator_type alloc = allocator_type()) :
			_val_alloc(alloc),
			_node_alloc(node_allocator()),
			_compare(comp)
		{
#ifdef PRINT_MSG
			cout << GREEN "RedBlackTree default consturctor called" RESET << endl;
#endif
			_sentinal = create_node(value_type());
			_sentinal->colour = RBT_BLACK;
			_sentinal->is_sentinal = true;
			_sentinal->parent = _sentinal;
			_sentinal->left = _sentinal;
			_sentinal->right = _sentinal;
			_size = 0;
			_root = _sentinal;
		}

		/*
		 * copy constructor.
		 *
		 * Copies the value and the shape of the tree.
		 * */

		RedBlackTree(const RedBlackTree &other) :
			_val_alloc(other._val_alloc),
			_node_alloc(other._node_alloc),
			_compare(other._compare)
		{
#ifdef PRINT_MSG	
			cout << GREEN "RedBlackTree Copy Constructor called" RESET << endl;
#endif
			this->_sentinal = create_node(value_type());
			this->_sentinal->colour = RBT_BLACK;
			this->_sentinal->is_sentinal = true;
			this->_size = other._size;
			this->_root = this->_sentinal;
			if (other._root == other._sentinal)
				return ;
			copy_tree(this->_root, other._root, other);
		}

		template <class InputIterator>
		RedBlackTree(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
					InputIterator>::type* = nullptr) :
			_val_alloc(alloc),
			_node_alloc(node_allocator()),
			_compare(comp)
		{
#ifdef PRINT_MSG
			cout << GREEN "RedBlackTree Range Constructor called" RESET << endl;
#endif
			_sentinal = create_node(value_type());
			_sentinal->colour = RBT_BLACK;
			_sentinal->is_sentinal = true;
			_sentinal->parent = _sentinal;
			_sentinal->left = _sentinal;
			_sentinal->right = _sentinal;
			_size = 0;
			_root = _sentinal;
			for (; first != last; first++)
				insert_node(*first);
		}

		/*
		 * default destructor.
		 * */

		~RedBlackTree()
		{
#ifdef PRINT_MSG
			cout << RED "RedBlackTree destructor called" RESET << endl;
#endif
			delete_tree(_root);
			free_node(_sentinal);
		}

		RedBlackTree	&operator=(const RedBlackTree &other)
		{
#ifdef PRINT_MSG
			cout << RED "RedBlackTree Copy Assignment Operator called" RESET << endl;
#endif
			if (_size != 0)
				delete_tree(_root);
			this->_sentinal = create_node(value_type());
			this->_sentinal->colour = RBT_BLACK;
			this->_sentinal->is_sentinal = true;
			this->_size = other._size;
			this->_root = this->_sentinal;
			if (other._root == other._sentinal)
				return (*this);
			copy_tree(this->_root, other._root, other);
			return (*this);
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

		node_pointer	insert_node(const value_type &val)
		{
			//if tree has no elements
			if (_root == _sentinal)
			{
				_root = create_node(val);
				_root->colour = RBT_BLACK;
				_sentinal->parent = _root;
				_size++;
				_sentinal->right = _root;
				_sentinal->left = _root;
				return (_root);
			}

			//normal insert
			node_pointer	front = _root;
			node_pointer	back = _root;
			node_pointer	insert = create_node(val);
			while (front != _sentinal)
			{
				back = front;
				if (_compare(*insert->data, *front->data))
					front = front->left;
				else
					front = front->right;
			}

			if (_compare(*insert->data, *back->data))
				back->left = insert;
			else
				back->right = insert;
			insert->parent = back;

			_size++;
			insert_fixup(insert);
			_sentinal->parent = _sentinal;
			_sentinal->left = min(_root);
			_sentinal->right = max(_root);
			return (insert);
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
		 *
		 * 	@param 'val' : the val to look for in the tree to delete.
		 * */

		void	delete_node(value_type val)
		{
			node_pointer	z = search_tree(_root, val);
			node_pointer	y = z;
			node_pointer	x;
			bool			original_colour = y->colour;

			if (z == _sentinal)
				return ;
			if (z->left == _sentinal) //case 1
			{
				x = z->right;
				transplant(z, x);
			}
			else if (z->right == _sentinal) //case 2
			{
				x = z->left;
				transplant(z, x);
			}
			else //case 3
			{
				y = minimum_in_subtree(z->right);
				x = y->right;
				original_colour = y->colour;
				if (y->parent == z)
					x->parent = y; //*
				else 
				{
					transplant(y, y->right); //**
					y->right = z->right;
					y->right->parent = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->colour = z->colour;
			}
			free_node(z);
			_size--;
			if (original_colour == RBT_BLACK)
				delete_fixup(x);
			_sentinal->parent = _sentinal;
			_sentinal->left = min(_root);
			_sentinal->right = max(_root);
		}

		/*
		 * find.
		 * Searches the tree for the val passed in.
		 * 
		 * @note : just used to call the private
		 * 	function search_tree
		 *
		 * @param 'val' : the val to look for in the tree.
		 * */

		node_pointer	find(const value_type &val) const
		{
			return (search_tree(_root, val));
		}

		/*
		 * clear.
		 *
		 * Clears the tree but doesnt delete the root.
		 * */

		void	clear(void)
		{
			delete_tree(_root);
			_sentinal->colour = RBT_BLACK;
			_sentinal->is_sentinal = true;
			_sentinal->parent = _sentinal;
			_sentinal->left = _sentinal;
			_sentinal->right = _sentinal;
			_size = 0;
			_root = _sentinal;
		}

		/*
		 * swap.
		 *
		 * Swaps the contents of one tree with the other.
		 * Also swaps the allocator and comparator.
		 *
		 * @note : needs to keep iterator validity after swapping.
		 * @note : I shouldve probably made a ft::swap or something.
		 *
		 * @param 'to_swap' : the tree to swap its contents with.
		 * */

		void	swap(RedBlackTree &to_swap)
		{
			allocator_type	temp_val_alloc(to_swap._val_alloc);
			node_allocator	temp_node_alloc(to_swap._node_alloc);
			node_pointer	temp_sentinal(to_swap._sentinal);
			node_pointer	temp_root(to_swap._root);
			key_compare		temp_compare(to_swap._compare);
			size_type		temp_size(to_swap._size);

			to_swap._val_alloc = this->_val_alloc;
			to_swap._node_alloc = this->_node_alloc;
			to_swap._sentinal = this->_sentinal;
			to_swap._root = this->_root;
			to_swap._compare = this->_compare;
			to_swap._size = this->_size;

			this->_val_alloc = temp_val_alloc;
			this->_node_alloc = temp_node_alloc;
			this->_sentinal = temp_sentinal;
			this->_root = temp_root;
			this->_root = temp_root;
			this->_compare = temp_compare;
			this->_size = temp_size;
		}

		/*
		 * inorder_traversal.
		 * */

		void	inorder_traversal(node_pointer node)
		{
			if (node != _sentinal)
			{
				inorder_traversal(node->left);

				if (node->colour == RBT_BLACK)
					cout << RED; //idk why my red is black
				else if (node->colour == RBT_RED)
					cout << GREEN; //idk why green is red
				cout << *node->data << RESET << endl;

				inorder_traversal(node->right);
			}
		}

		void	postorder_traversal(node_pointer node)
		{
			if (node != _sentinal)
			{
				postorder_traversal(node->left);
				postorder_traversal(node->right);

				if (node->colour == RBT_BLACK)
					cout << RED; //idk why my red is black
				else if (node->colour == RBT_RED)
					cout << GREEN; //idk why green is red
				cout << *node->data << RESET << endl;
			}
		}

		void	preorder_traversal(node_pointer node)
		{
			if (node != _sentinal)
			{
				if (node->colour == RBT_BLACK)
					cout << RED; //idk why my red is black
				else if (node->colour == RBT_RED)
					cout << GREEN; //idk why green is red
				cout << *node->data << RESET << endl;

				preorder_traversal(node->left);
				preorder_traversal(node->right);
			}
		}


		/*
		 * print_helper.
		 * */

		//void	print_helper(node_pointer n, std::string indent, bool last,
		//		typename ft::enable_if<!ft::is_integral<value_type>::value,
		//			value_type>::type* = nullptr)
		//{
		//	if (n != _sentinal)
		//	{
		//		cout << indent;
		//		if (last)
		//		{
		//			cout << "R----";
		//			indent += "     ";
		//		}
		//		else
		//		{
		//			cout << "L----";
		//			indent += "|    ";
		//		}
		//		cout << "[" <<(*n->data).first << "," << (*n->data).second << "]"
		//			<< (n->colour == RBT_BLACK ? RED : GREEN)
		//			<< "(" << (n->colour == RBT_BLACK ? "B" : "R")
		//			<< ")" RESET << endl;
		//		print_helper(n->left, indent, false);
		//		print_helper(n->right, indent, true);
		//	}
		//}

		//void	print_helper(node_pointer n, std::string indent, bool last,
		//		typename ft::enable_if<ft::is_integral<value_type>::value,
		//			value_type>::type* = nullptr)
		//{
		//	if (n != _sentinal)
		//	{
		//		cout << indent;
		//		if (last)
		//		{
		//			cout << "R----";
		//			indent += "     ";
		//		}
		//		else
		//		{
		//			cout << "L----";
		//			indent += "|    ";
		//		}
		//		cout << *n->data << (n->colour == RBT_BLACK ? RED : GREEN)
		//			<< "(" << (n->colour == RBT_BLACK ? "B" : "R")
		//			<< ")" RESET << endl;
		//		print_helper(n->left, indent, false);
		//		print_helper(n->right, indent, true);
		//	}
		//}

		void	print_pair(node_pointer n, std::string indent, bool last)
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
				cout << "[" <<(*n->data).first << "," << (*n->data).second << "]"
					<< (n->colour == RBT_BLACK ? RED : GREEN)
					<< "(" << (n->colour == RBT_BLACK ? "B" : "R")
					<< ")" RESET << endl;
				print_pair(n->left, indent, false);
				print_pair(n->right, indent, true);
			}
		}

		void	print(node_pointer n, std::string indent, bool last)
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
				cout << *n->data << (n->colour == RBT_BLACK ? RED : GREEN)
					<< "(" << (n->colour == RBT_BLACK ? "B" : "R")
					<< ")" RESET << endl;
				print(n->left, indent, false);
				print(n->right, indent, true);
			}
		}


		/*
		 * get_root.
		 * Returns root of tree.
		 * */

		node_pointer	get_root(void) const
		{
			return (this->_root);
		}

		/*
		 * get_sentinal
		 * Returns the sentinal of the tree.
		 * */

		node_pointer	get_sentinal(void) const
		{
		 	return (this->_sentinal);
		}

		/*
		 * size.
		 * Returns the size of the tree.
		 * */

		size_type		size(void) const
		{
			return (_size);
		}

		/*
		 * Returns a true or false depending on wheather or
		 * not the RBT is empty.
		 * */

		bool			empty(void) const
		{
			if (_size == 0)
				return true;
			return false;
		}

		/*
		 * Returns the max size of the rbt.
		 * */

		size_type	max_size(void) const
		{
			return (size_type(-1));
		}

		key_compare	key_comp(void)	const
		{
			return (this->_compare);
		}

		/*
		 * is_sentinal.
		 *
		 * Returns a tree or false if 
		 * the node is a sentinal or not.
		 *
		 * @edit : I technically dont need this after adding
		 * 	is_sentinal in node variables.
		 *
		 * @param 'node' : the node the check wheather 
		 * 	or not it is a sentinal
		 * */

		bool	is_sentinal(node_pointer node)
		{
			if (node == _sentinal)
				return (true);
			return (false);
		}

		node_pointer	min(node_pointer node) const
		{
			while (node != _sentinal && node->left != _sentinal)
				node = node->left;
			return node;
		}

		node_pointer	max(node_pointer node) const
		{
			while (node != _sentinal && node->right != _sentinal)
				node = node->right;
			return node;
		}

		iterator	begin(void)
		{
			return (iterator(min(_root)));
		}

		const_iterator	begin(void) const
		{
			return (const_iterator(min(_root)));
		}

		reverse_iterator	rbegin(void)
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (const_reverse_iterator(end()));
		}

		iterator	end(void)
		{
			return (iterator(_sentinal));
		}

		const_iterator	end(void) const
		{
			return (const_iterator(_sentinal));
		}

		reverse_iterator	rend(void)
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator	rend(void) const
		{
			return (const_reverse_iterator(begin()));
		}

	private:

		/*
		 * Helper function for rbt destructor.
		 * */

		/*
		 * create_node.
		 *
		 * All 3 are helper functions to allocate and 
		 * construct a node using allocator.
		 *
		 * @note : alloc.construct will call the constructor,
		 * 	copy constructor and destructor.
		 *
		 * @param 'val' : the value to fill the node with.
		 * */

		node_pointer	create_node(const value_type &val)
		{
			node_pointer	node;
			pointer			val_ptr;

			val_ptr = _val_alloc.allocate(1);
			_val_alloc.construct(val_ptr, val);

			node = _node_alloc.allocate(1);
			_node_alloc.construct(node, Node<value_type>(val_ptr, _sentinal, _sentinal, _sentinal, RBT_RED));
			return (node);
		}

		/*
		 * copy_node.
		 *
		 * Copies the node and the value of the node using 
		 * the appropriate allocater.
		 *
		 * @param 'to_copy' : the value of the node to copy.
		 * */

		node_pointer	copy_node(node_pointer to_copy)
		{
			node_pointer	node;
			pointer			val_ptr;

			val_ptr = _val_alloc.allocate(1);
			_val_alloc.construct(val_ptr, *to_copy->data);
			
			node = _node_alloc.allocate(1);
			_node_alloc.construct(node, Node<value_type>(val_ptr, _sentinal, _sentinal, _sentinal, to_copy->colour));
			return (node);
		}

		/*
		 * free_node.
		 *
		 * Frees and deletes a node and its value using the 
		 * approprivate allocater.
		 * Destroys the value and deallocates the value.
		 * Destroys the node and deallocates the node.
		 *
		 * @param 'node' : the node to be freed and deleted.
		 * */

		void	free_node(node_pointer node)
		{
			_val_alloc.destroy(node->data);
			_val_alloc.deallocate(node->data, 1);
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
		}

		/*
		 * delete_tree.
		 *
		 * Recursively deletes the tree from left to right.
		 *
		 * @param 'node' : initial value to pass in will be the root
		 * 	of the tree to delete. After that it will recursively pass it
		 * 	self down as node->left and node->right.
		 * */

		void	delete_tree(node_pointer node)
		{
			if (node != _sentinal)
			{
				delete_tree(node->left);
				delete_tree(node->right);
				free_node(node);
			}
		}

		/*
		 * copy_tree.
		 *
		 * Recursively copies a tree from the left to the right.
		 * The structure will remain the same.
		 *
		 * @edit : after making a is_sentinal param in node I
		 * 	techically dont need this.
		 *
		 * @param 'to_paste' : initial value will be the root of the current
		 * 	tree. When it enteres recursively it will continue to go to the 
		 * 	left side of the tree than the right.
		 * @param 'to_copy' : initial value will be the root of the
		 * 	tree to copy. When it enteres recursively it will continue to go
		 * 	to the left side of the tree than the right.
		 * @param 'other' : the object of the other tree. I need this to compare
		 * 	sentinals as the value of 2 trees sentinals are not the same.
		 * */

		void	copy_tree(node_pointer to_paste, node_pointer to_copy, const RedBlackTree &other)
		{
			if (to_copy == other._sentinal)
				return ;
			if (_root == _sentinal)
			{
				_root = copy_node(to_copy);
				copy_tree(_root, to_copy, other);
			}
			if (to_copy->left != other._sentinal)
			{
				to_paste->left = copy_node(to_copy->left);
				to_paste->left->parent = to_paste;
				copy_tree(to_paste->left, to_copy->left, other);
			}
			if (to_copy->right != other._sentinal)
			{
				to_paste->right = copy_node(to_copy->right);
				to_paste->right->parent = to_paste;
				copy_tree(to_paste->right, to_copy->right, other);
			}
		}

		/*
		 * search_tree.
		 *
		 * Searches the tree for a value given the starting node.
		 *
		 * @param 'node' : root or subtree to be given to search all child for
		 * 	value 'to_find'
		 * @param 'to_find' : the value held in a node to look for.
		 * */

		node_pointer	search_tree(node_pointer node, const value_type &to_find) const
		{
			if (node == _sentinal)
				return node;
			if (_compare(to_find, *node->data))
				return search_tree(node->left, to_find);
			if (_compare(*node->data, to_find))
				return search_tree(node->right, to_find);
			return node;
		}

		/*
		 * get_sibling.
		 *
		 * Returns the sibling of node x.
		 *
		 * @param 'x' : the value to get the sibling of.
		 * */

		node_pointer	get_sibling(node_pointer x)
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

		void	transplant(node_pointer x, node_pointer y)
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

		void	left_rotate(node_pointer x)
		{
			node_pointer y = x->right;
			node_pointer b = y->left;
			transplant(x, y);
			x->right = b;
			if (b != _sentinal)
				b->parent = x;
			y->left = x;
			x->parent = y;
		}

		/*
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

		void	right_rotate(node_pointer x)
		{
			node_pointer y = x->left;
			node_pointer b = y->right;
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

		node_pointer	minimum_in_subtree(node_pointer n)
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

		node_pointer	maximum_in_subtree(node_pointer n)
		{
			while (n->right != _sentinal)
				n = n->right;
			return (n);
		}

		/*
		 * insert_fixup.
		 *
		 * There are 3 cases for insert_fixup. The fixup code has been
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

		void	insert_fixup(node_pointer z)
		{
			while (z->parent->colour == RBT_RED && z != _root)
			{
				node_pointer	par = z->parent;
				node_pointer	gp = par->parent;
				node_pointer	unc = get_sibling(par);
				if (par == gp->left) //if parent is left child
				{
					if (unc->colour == RBT_RED) //if uncle is red
					{
						par->colour = RBT_BLACK;
						unc->colour = RBT_BLACK;
						gp->colour = RBT_RED;
						z = gp;
					}
					else //if uncle is black (case 2 or case 3)
					{
						if (z == par->right) //child is right and parent is left (case 2)
						{
							z = par;
							left_rotate(z);
							par = z->parent;
							gp = par->parent;
							unc = get_sibling(par);
						}
						par->colour = RBT_BLACK;
						gp->colour = RBT_RED;
						right_rotate(gp);
					}
				}
				else //if parent is right child
				{
					if (unc->colour == RBT_RED) //if uncle is red
					{
						par->colour = RBT_BLACK;
						unc->colour = RBT_BLACK;
						gp->colour = RBT_RED;
						z = gp;
					}
					else //if uncle is black (case 2 or case 3)
					{
						if (z == par->left) //child is left and parent is right (case 2)
						{
							z = par;
							right_rotate(z);
							par = z->parent;
							gp = par->parent;
							unc = get_sibling(par);
						}
						par->colour = RBT_BLACK;
						gp->colour = RBT_RED;
						left_rotate(gp);
					}
				}
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

		void	delete_fixup(node_pointer x)
		{
			while (x != _root && x->colour == RBT_BLACK)
			{
				if (x == x->parent->left) //if x is left child
				{
					node_pointer	w = get_sibling(x);
					if (w->colour == RBT_RED) //case 1
					{
						w->colour = RBT_BLACK;
						x->parent->colour = RBT_RED;
						left_rotate(x->parent);
						w = x->parent->right;
					}
					if (w->left->colour == RBT_BLACK &&
							w->right->colour == RBT_BLACK) //case 2
					{
						w->colour = RBT_RED;
						x = x->parent;
					}
					else //case 3 and case 4
					{
						if (w->right->colour == RBT_BLACK) //case 3
						{
							w->left->colour = RBT_BLACK;
							w->colour = RBT_RED;
							right_rotate(w);
							w = x->parent->right;
						}
						w->colour = x->parent->colour;
						x->parent->colour = RBT_BLACK;
						w->right->colour = RBT_BLACK;
						left_rotate(x->parent);
						x = _root;
					}
				}
				else //if x is right child
				{
					node_pointer	w = get_sibling(x);
					if (w->colour == RBT_RED)
					{
						w->colour = RBT_BLACK;
						x->parent->colour = RBT_RED;
						right_rotate(x->parent);
						w = x->parent->left;
					}
					if (w->left->colour == RBT_BLACK &&
							w->right->colour == RBT_BLACK) //case 2
					{
						w->colour = RBT_RED;
						x = x->parent;
					}
					else
					{
						if (w->left->colour == RBT_BLACK)
						{
							w->right->colour = RBT_BLACK;
							w->colour = RBT_RED;
							left_rotate(w);
							w = x->parent->left;
						}
						w->colour = x->parent->colour;
						x->parent->colour = RBT_BLACK;
						w->left->colour = RBT_BLACK;
						right_rotate(x->parent);
	  					x = _root;
					}
				}
			}
			x->colour = RBT_BLACK;
		}
};

#endif
