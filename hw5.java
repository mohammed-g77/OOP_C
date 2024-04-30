/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java2;

import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int x) {
        data = x;
        next = null;
    }
}

class LinkedList {
    Node head;

    public LinkedList() {
        head = null;
    }

    public void insert(int x) {
        Node newNode = new Node(x);
        newNode.next = head;
        head = newNode;
    }
}

class Stack extends LinkedList {
    public boolean isEmpty() {
        return head == null;
    }

    public void push(int e) {
        insert(e);
    }

    public int pop() {
        int result = 0;
        if (!isEmpty()) {
            result = head.data;
            head = head.next;
        }
        return result;
    }
}

public class Java2 {

    public static void toHexadecimal(Stack s, int n) {
        int remainder;
        while (n > 0) {
            remainder = n % 16;
            s.push(remainder);
            n /= 16;
        }
    }

    public static void main(String[] args) {
        Stack stack = new Stack();
        int n;

        Scanner scanner = new Scanner(System.in);

        do {
            System.out.print("Enter a positive integer value: ");
            n = scanner.nextInt();
        } while (n <= 0);

        // Convert the number to Hexadecimal using the stack
        toHexadecimal(stack, n);

        System.out.print("Hexadecimal equivalent: ");

        while (!stack.isEmpty()) {
            int digit = stack.pop();
            if (digit < 10) {
                System.out.print(digit);
            } else {
                char hexChar = (char) ('A' + digit - 10);
                System.out.print(hexChar);
            }
        }

        System.out.println();
    }
}
