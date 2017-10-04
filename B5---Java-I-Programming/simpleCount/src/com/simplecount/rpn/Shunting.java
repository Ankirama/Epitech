package com.simplecount.rpn;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

/**
 * @author ankirama
 * Class to convert infix to shunting yard format (42 + 3 -> 42 3 +)
 */
public class Shunting extends ARpn {
    private Deque<String> m_stack; /**< it will contain operators and parenthesis */
    private ArrayList<String>   m_result; /**< it will contain the RPN result like 4 2 + */

    /**
     * Constructor
     * It will init our 2 variables
     */
    public Shunting() {
        this.m_stack = new ArrayDeque<>();
        this.m_result = new ArrayList<>();
    }

    /**
     * Called for each token like 4 + 2
     * it will check the current token and will do the shunting-yard algo (used to convert infix -> RPN)
     * @param token current token like 42 or +
     */
    public void convertCurrentToken(String token) {
        if (this.isOperator(token)) {
            while (!this.m_stack.isEmpty() && this.isOperator(this.m_stack.getFirst()) &&
                    this.compareAssio(token, this.m_stack.getFirst())) {
                this.m_result.add(this.m_stack.removeFirst());
            }
            this.m_stack.addFirst(token);
        } else if (token.equals("(")) {
            this.m_stack.addFirst(token);
        } else if (this.isScope(token)) {
            this.m_stack.addFirst(token);
        } else if (token.equals(")")) {
            while (!this.m_stack.isEmpty() && !this.m_stack.getFirst().equals("(") &&
                    !this.isScope(this.m_stack.getFirst())) {
                this.m_result.add(this.m_stack.removeFirst());
            }
            if (this.m_stack.getFirst().equals("(")) {
                this.m_stack.removeFirst();
            }
            else {
                this.m_result.add(this.m_stack.removeFirst());
            }
        } else {
            this.m_result.add(token);
        }
    }

    /**
     * Travel stack until end and add it to our array String (our result)
     */
    public void emptyStack() {
        while (!this.m_stack.isEmpty()) {
            this.m_result.add(this.m_stack.removeFirst());
        }
    }

    /**
     * Getter to get m_result
     * @return m_result
     */
    public ArrayList<String> getResult() {
        return this.m_result;
    }

    /**
     * debug function to display the convertion (on stdout)
     */
    public void displayShunting() {
        for (String token: this.m_result) {
            System.out.print(token + " ");
        }
    }

    /**
     * reset our variables
     */
    public void clean() {
        this.m_stack = new ArrayDeque<>();
        this.m_result = new ArrayList<>();
    }

    /**
     * Function to check wich token has greater precedence (only same assiociative)
     * if > 0 then just add in stack (for example token1 = *, token2 = + -> res > 0)
     * @param token1 could be + - ...
     * @param token2 could be + - ...
     * @return boolean about our compare function
     */
    private boolean compareAssio(String token1, String token2) {
        return ((this.isAssociative(token1, LEFT_ASSOCIATIVE) && this.comparePrecedence(token1, token2) <= 0) ||
                (this.isAssociative(token1, RIGHT_ASSOCIATIVE) && this.comparePrecedence(token1, token2) < 0));
    }

}
