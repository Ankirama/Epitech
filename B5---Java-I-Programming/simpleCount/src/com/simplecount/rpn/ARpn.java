package com.simplecount.rpn;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

/**
 * @author ankirama
 *
 * Abstract class used for our RPN class and Shunting Yard class
 */
public abstract class ARpn {
    protected static final int LEFT_ASSOCIATIVE = 0;
    protected static final int RIGHT_ASSOCIATIVE = 1;

    protected static final int ADD_PRECEDENCE = 0;
    protected static final int MULT_PRECEDENCE = 1;
    protected static final int ROOT_PRECEDENCE = 2;

    /**
     * @value It will contain our operators like + - etc
     * int[] for {precedence, associative}
     */
    protected static final HashMap<String, int[]> OPERATOR;
    static {
        OPERATOR = new HashMap<String, int[]>();
        OPERATOR.put("+", new int[]{ADD_PRECEDENCE, LEFT_ASSOCIATIVE});
        OPERATOR.put("-", new int[]{ADD_PRECEDENCE, LEFT_ASSOCIATIVE});

        OPERATOR.put("*", new int[]{MULT_PRECEDENCE, LEFT_ASSOCIATIVE});
        OPERATOR.put("/", new int[]{MULT_PRECEDENCE, LEFT_ASSOCIATIVE});
        OPERATOR.put("%", new int[]{MULT_PRECEDENCE, LEFT_ASSOCIATIVE});

        OPERATOR.put("^", new int[]{ROOT_PRECEDENCE, LEFT_ASSOCIATIVE});
    }

    /**
     * @value It will contain our scope functions like sqrt, cos etc...
     * It will be used with an unique operator. It's like a (
     * they will be considered like a parenthesis and the stronger operator (priority)
     */
    protected static final Set<String> SCOPE = new HashSet<String>(Arrays.asList(
            new String[] {
                    "sqrt",
                    "cos",
                    "sin",
                    "tan",
                    "ln",
                    "exp",
                    "log",
            }
    ));

    /**
     * return if the OPERATOR hashmap contains the token (like +)
     * @param token token we want to check like +
     * @return true if the token is in the hashmap, else false
     */
    protected boolean isOperator(String token) {
        return OPERATOR.containsKey(token);
    }

    protected boolean isScope(String token) {
        return SCOPE.contains(token);
    }

    /**
     * It will check if it's a left_associative or right_associative
     * @param token token we want to check like +
     * @param typeAssociative type like LEFT_ASSOCIATIVE / RIGHT_ASSOCIATIVE
     * @return false if any error (could be stupid but errors are forbidden!) or if the type isn't the same, else True
     */
    protected boolean isAssociative(String token, int typeAssociative) {
        return isOperator(token) && OPERATOR.get(token)[1] == typeAssociative;
    }

    /**
     * compare precedence between 2 operators
     * it will not check errors
     * @param token1 first operator we want to check
     * @param token2 second operator we want to check
     * @return 0 if token1 = token2, else like a strcmp (-X if token1 < token2) etc..
     */
    protected int comparePrecedence(String token1, String token2) {
        return OPERATOR.get(token1)[0] - OPERATOR.get(token2)[0];
    }
}
