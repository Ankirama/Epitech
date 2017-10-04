package com.simplecount.rpn;

import java.util.*;

public class Rpn extends ARpn {
    private static final Set<String> ALLOWED_OPERATOR = new HashSet<String>(Arrays.asList(
            new String[] {
                    "+", "-", "*", "/", "%", "^"
            }
    ));

    /**
     * check if the token is in our ALLOWED_OPERATOR
     * @param token token we want to check like +
     * @return true if we found it, else false
     */
    protected boolean isOperator(String token) {return ALLOWED_OPERATOR.contains(token);}

    /**
     * we will check op and do the right operation
     * @param op string like + ^ - %
     * @param value2 second value (it's first because we use a stack) we will use for our operation
     * @param value1 first value we will use for our operation
     * @return result from our operation
     */
    private double evalOperation(String op, double value2, double value1) {
        double result = 0;
        switch (op) {
            case "+":
                result = value1 + value2;
                break;
            case "-":
                result = value1 - value2;
                break;
            case "/":
                if (value2 == 0) {
                    throw new IllegalArgumentException("division by zero");
                } else {
                  result = value1 / value2;
                }
                break;
            case "*":
                result = value1 * value2;
                break;
            case "%":
                if (value2 == 0) {
                    throw new IllegalArgumentException("modulo by zero");
                } else if (value2 < 0) {
                    throw new IllegalArgumentException("modulo by negative number");
                } else {
                    result = value1 % value2;
                }
                break;
            case "^":
                result = Math.pow(value1, value2);
                break;
            default:
                throw new IllegalArgumentException("bad operator");
        }
        return result;
    }

    /**
     * we will check op and do the right operation
     * @param op string like sqrt, ln, ...
     * @param value value we will use to do our operation
     * @return result from our operation
     */
    private double evalOperation(String op, double value) {
        double result = 0;

        switch (op) {
            case "sqrt":
                if (value < 0) {
                    throw new IllegalArgumentException("sqrt with neg value");
                }
                result = Math.sqrt(value);
                break;
            case "cos":
                result = Math.cos(Math.toRadians(value));
                break;
            case "sin":
                result = Math.sin(Math.toRadians(value));
                break;
            case "tan":
                result = Math.tan(Math.toRadians(value));
                break;
            case "ln":
                if (value < 0) {
                    throw new IllegalArgumentException("ln with neg value");
                }
                result = Math.log10(value);
                break;
            case "log":
                result = Math.log(value);
            case "exp":
                result = Math.exp(value);
                break;
            default:
                throw new IllegalArgumentException("bad operator");
        }
        return result;
    }

    /**
     * we will travel our tokens and create our stack to do our calculs
     * @param tokens like {"42", "0", "+", ...}
     * @return number with our result from our calculs
     */
    public double evalExpression(ArrayList<String> tokens) {
        Deque<Double> stack = new ArrayDeque<>();

        for (String token: tokens) {
            if (isOperator(token)) {
                try {
                    if (!stack.isEmpty()) {
                        double tmp1 = stack.removeFirst();
                        if (!stack.isEmpty()) {
                            double tmp2 = stack.removeFirst();
                            stack.addFirst(this.evalOperation(token, tmp1, tmp2));
                        } else {
                            throw new IllegalArgumentException("Error");
                        }
                    } else {
                        throw new IllegalArgumentException("Error");
                    }
                } catch (IllegalArgumentException err) {
                    throw new IllegalArgumentException(err);
                }
            } else if (isScope(token)) {
                try {
                    if (!stack.isEmpty()) {
                        stack.addFirst(this.evalOperation(token, stack.removeFirst()));
                    } else
                        throw new IllegalArgumentException("Error");
                } catch (IllegalArgumentException err) {
                    throw new IllegalArgumentException(err);
                }
            } else {
                stack.addFirst(Double.parseDouble(token));
            }
        }
        if (stack.isEmpty())
            throw new IllegalArgumentException("Error");
        return stack.removeFirst();
    }

    /**
     * Constructor
     *
     * Do nothing
     */
    public Rpn() {}
}
