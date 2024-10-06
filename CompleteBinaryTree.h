#pragma once

#include <iostream>
#include <cmath>
#include <fstream>

template <typename T>
struct CompleteBinaryTree {
private:
	template <typename U>
	struct CBTList {
	private:
		template <typename D>
		struct Node {
			D value;
			Node<D>* next;

			Node(D value) : value(value), next(nullptr) {}
		};

		Node<U>* head;
		Node<U>* tail;

	public:
		CBTList() : head(nullptr), tail(nullptr) {}

		bool is_empty() {
			return head == nullptr;
		}

		void push(U value) {
			Node<U>* newNode = new Node<T>(value);
			if (is_empty()) {
				head = newNode;
				tail = newNode;
				return;
			}
			tail->next = newNode;
			tail = newNode;
		}

		void pop() {
			if (is_empty()) return;
			Node<U>* prevNode = NULL;
			Node<U>* curNode = head;
			while (curNode->next) {
				prevNode = curNode;
				curNode = curNode->next;
			}
			if (prevNode) prevNode->next = nullptr;
			tail = prevNode;
			delete curNode;
		}

		int32_t size() {
			int32_t size = 0;
			Node<U>* tempNode = head;
			while (tempNode) {
				tempNode = tempNode->next;
				size++;
			}
			return size;
		}

		U find(U value) {
			Node<U>* tempNode = head;
			while (tempNode) {
				if (tempNode->value == value) return value;
				tempNode = tempNode->next;
			}
			return NULL;
		}

		void print() {
			Node<U>* tempNode = head;
			Node<U>* sizeNode = head;
			int32_t size = 0;
			while (sizeNode) {
				sizeNode = sizeNode->next;
				size++;
			}
			int32_t depth = 1 + floor(log2(size));
			int32_t space = 15 * (depth - 2);
			for (int32_t currentDepth = 0, y = pow(2, depth); currentDepth < depth; currentDepth++, y = y / 2, space = floor(space / 2)) {
				int32_t amountOfItemsPerLevel = pow(2, currentDepth);
				for (int32_t i = 0; tempNode and i < amountOfItemsPerLevel; i++) {
					if (i == 0) for (int32_t j = 0; j < y; j++) std::cout << " ";
					std::cout << tempNode->value;
					for (int32_t j = 0; j < space; j++) std::cout << " ";
					tempNode = tempNode->next;
				}
				std::cout << std::endl;
			}
		}

		void printInFile(std::ofstream& file){
			if (is_empty()) return;
			Node<T>* printNode = head;
			while (printNode) {
				file << printNode->value << " ";
				printNode = printNode->next;
			}
			file << std::endl;
		}

	};

	CBTList<T> BinaryTree;
public:

	void TINSERT(T value) {
		BinaryTree.push(value);
	}

	void TDEL() {
		BinaryTree.pop();
	}

	T TGET(T value) {
		return BinaryTree.find(value);
	}

	void print() {
		BinaryTree.print();
	}

	void printInFile(std::ofstream& file){
		BinaryTree.printInFile(file);
	}
};
