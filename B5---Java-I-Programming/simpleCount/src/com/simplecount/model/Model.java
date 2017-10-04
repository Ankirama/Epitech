package com.simplecount.model;

import com.simplecount.rpn.Rpn;
import com.simplecount.rpn.Shunting;

import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Observable;

public class Model extends Observable {
    private static final int TOKEN_NUMBER = 0;
    private static final int TOKEN_OPEN_SCOPE = 1;
    private static final int TOKEN_CLOSE_SCOPE = 2;
    private static final int TOKEN_OPERATOR = 3;

    private String      m_answerText; /**< It will contain the final answer from current expression */
    private String      m_currentOperation; /**< It will contain the current operation, or 0 */
    private int         m_parenthesis; /**< counter to know how many parenthesis we have */
    private int   m_typeLastToken; /**< It will contain the type of last token like operator etc */
    private Shunting    m_converter; /**< class to convert infix to shunting yard format. Used for rpn calcul */
    private Rpn         m_rpn; /**< class to calcul with rpn */
    private String      m_currentToken; /**< it will contain current number like 4 if button 4 pressed, then 42 if button 2 pressed*/
    private String      m_operatorToken; /**< it will contain current operator like + - ^ ... */
    private boolean     m_equalApplied; /**< true after button = pressed */
    private boolean     m_dotUsed; /**< used to allow only one dot per number */
    private boolean     m_minusUsed; /**< used to check if we have to add or remove a minus from our current number */
    private boolean     m_error; /**< used to check if we have any error and display a specific message + reset after */

    /**
     * Constructor
     * it will set default variables
     */
    public Model() {
        this.m_answerText = "";
        this.m_currentOperation = "0";
        this.m_typeLastToken = TOKEN_NUMBER;
        this.m_parenthesis = 0;
        this.m_converter = new Shunting();
        this.m_rpn = new Rpn();
        this.m_currentToken = "0";
        this.m_operatorToken = "";
        this.m_equalApplied = false;
        this.m_dotUsed = false;
        this.m_error = false;
        this.notifyViaObservable(this);
    }

    /**
     * Used to update currentToken if it's a number
     * @param newValue new value like 9 or 3 etc...
     */
    public void updateNumber(String newValue) {
        if (this.m_error) {
            this.reset();
        }
        if (this.m_typeLastToken == TOKEN_OPERATOR) {
            this.m_converter.convertCurrentToken(this.m_operatorToken);
        }
        if (this.m_currentOperation.equals("0") || this.m_equalApplied) {
            this.m_equalApplied = false;
            this.m_answerText = "Ans = " + this.m_currentOperation;
            this.m_currentToken = newValue;
            this.m_currentOperation = newValue;
        } else {
            if (this.m_typeLastToken == TOKEN_CLOSE_SCOPE) {
                this.m_converter.convertCurrentToken("*");
                this.m_currentOperation += " \u00D7 ";
            }
            this.m_currentToken += newValue;
            this.m_currentOperation += newValue;
        }
        this.m_typeLastToken = TOKEN_NUMBER;
        this.notifyViaObservable(this);
    }

    /**
     * Check how to add (if possible) a dot (like 0.42) etc...
     */
    public void updateDot() {
        if (!this.m_dotUsed) {
            if (this.m_error) {
                this.reset();
            }
            if (this.m_typeLastToken != TOKEN_NUMBER) {
                this.m_converter.convertCurrentToken(this.m_operatorToken);
                this.m_currentToken = "0";
            }
            this.m_currentToken += ".";
            this.m_currentOperation += ".";
            this.m_dotUsed = true;
            this.m_typeLastToken = TOKEN_NUMBER;
            this.notifyViaObservable(this);
        }
    }

    /**
     * used to 'convert' current number (like 42 -> minus -> -42 -> minus -> 42)
     */
    public void updateMinus() {
        if (this.m_error) {
            this.reset();
        }
        if (this.m_minusUsed) {
            this.m_currentOperation = this.m_currentOperation.substring(0, this.m_currentOperation.length() - this.m_currentToken.length());
            this.m_currentToken = this.m_currentToken.substring(1);
            this.m_currentOperation += this.m_currentToken;

        } else {
            if (this.m_typeLastToken != TOKEN_NUMBER) {
                this.m_converter.convertCurrentToken(this.m_operatorToken);
                this.m_currentToken = "0";
            } else {
                this.m_currentOperation = this.m_currentOperation.substring(0, this.m_currentOperation.length() - this.m_currentToken.length());
            }
            this.m_currentToken = "-" + this.m_currentToken;
            this.m_currentOperation += this.m_currentToken;
        }
        this.m_minusUsed = !this.m_minusUsed;
        this.m_typeLastToken = TOKEN_NUMBER;
        this.notifyViaObservable(this);
    }

    /**
     * Update a basic operator like + ^ but not sqrt etc..
     * @param value
     */
    public void updateOperator(String value) {
        if (this.m_error) {
            this.reset();
        }
        if (this.m_typeLastToken != TOKEN_OPEN_SCOPE) {
            if (this.m_typeLastToken == TOKEN_OPERATOR) {
                this.m_currentOperation = this.m_currentOperation.substring(0, this.m_currentOperation.length() - this.m_operatorToken.length()
                        - 2 * " ".length());
            } else {
                this.m_converter.convertCurrentToken(this.m_currentToken);
                this.m_currentToken = "";
                this.m_dotUsed = false;
                this.m_minusUsed = false;
            }
            if (this.m_equalApplied) {
                this.m_answerText = "Ans = " + this.m_currentOperation;
                this.m_equalApplied = false;
            }
            this.m_operatorToken = value;
            this.m_currentOperation += " " + this.m_operatorToken + " ";
            this.m_typeLastToken = TOKEN_OPERATOR;
            this.notifyViaObservable(this);
        }
    }

    /**
     * clean all, like a new start
     */
    public void updateCleanAll() {
        this.reset();
        this.notifyViaObservable(this);
    }

    /**
     * Clean line with the current calcul and reset variables
     */
    public void updateCleanLine() {
        if (this.m_error) {
            this.reset();
        } else {
            this.m_currentToken = "0";
            this.m_currentOperation = "0";
            this.m_typeLastToken = TOKEN_NUMBER;
            this.m_parenthesis = 0;
            this.m_dotUsed = false;
            this.m_minusUsed = false;
            this.m_converter.clean();
        }
        this.notifyViaObservable(this);
    }

    /**
     * used when = button is pressed
     * It will call our rpn class and do the operation to calculate our result
     * it will add ) and last number created to use it in our calcul
     */
    public void updateEqual() {
        if (this.m_error) {
            this.reset();
        } else {
            if (this.m_typeLastToken == TOKEN_OPERATOR) {
                this.m_converter.convertCurrentToken(this.m_operatorToken);
            }

            if (this.m_currentToken.length() > 0) {
                this.m_converter.convertCurrentToken(this.m_currentToken);
            }
            while (this.m_parenthesis > 0) {
                this.m_converter.convertCurrentToken(")");
                --this.m_parenthesis;
                this.m_currentOperation += ")";
            }
            this.m_converter.emptyStack();
            this.m_answerText = this.m_currentOperation + " =";
            try {
                double tmp = this.m_rpn.evalExpression(this.m_converter.getResult());
                if (tmp == Double.NEGATIVE_INFINITY || tmp == Double.POSITIVE_INFINITY) {
                    this.m_error = true;
                }
                this.m_currentOperation = this.formatString(tmp);
                this.m_currentToken = this.m_currentOperation;
                this.m_converter.clean();
                this.m_equalApplied = true;
                this.m_typeLastToken = TOKEN_NUMBER;
            } catch (IllegalArgumentException err) {
                this.m_currentOperation = "Error";
                this.m_error = true;
            }
        }
        this.notifyViaObservable(this);
    }

    /**
     * used when scope function is called
     * scope function is a function like sqrt, ln, ... (with 1 operand)
     * used by listener
     * @param token scope we will check
     */
    public void updateOpenScope(String token) {
        if (this.m_error) {
            this.reset();
        }
        if (this.m_typeLastToken == TOKEN_OPERATOR) {
            this.m_converter.convertCurrentToken(this.m_operatorToken);
        }
        if (this.m_currentOperation.equals("0") || this.m_equalApplied) {
            this.m_equalApplied = false;
            this.m_answerText = "Ans = " + this.m_currentOperation;
            this.m_currentToken = "";
            this.m_currentOperation = token;
        } else {
            if (this.m_typeLastToken == TOKEN_NUMBER) {
                this.m_converter.convertCurrentToken(this.m_currentToken);
                this.m_converter.convertCurrentToken("*");
                this.m_currentOperation += " * ";

            } else if (this.m_typeLastToken == TOKEN_CLOSE_SCOPE) {
                this.m_converter.convertCurrentToken("*");
                this.m_currentOperation += " * ";
            }
            this.m_currentToken = "";
            this.m_currentOperation += token;
        }
        if (!token.equals("(")) {
            this.m_currentOperation += "(";
        }
        this.m_converter.convertCurrentToken(token);
        ++this.m_parenthesis;
        this.m_typeLastToken = TOKEN_OPEN_SCOPE;
        this.notifyViaObservable(this);
    }

    /**
     * Function when ) button is pressed
     * used by listener
     */
    public void updateCloseScope() {
        if (this.m_error) {
            this.reset();
        }
        if (this.m_parenthesis > 0 && (this.m_typeLastToken == TOKEN_NUMBER || this.m_typeLastToken == TOKEN_CLOSE_SCOPE)) {
            this.m_converter.convertCurrentToken(this.m_currentToken);
            this.m_converter.convertCurrentToken(")");
            --this.m_parenthesis;
            this.m_currentToken = "";
            this.m_currentOperation += ")";
            this.m_typeLastToken = TOKEN_CLOSE_SCOPE;
            this.notifyViaObservable(this);
        }
    }

    /**
     * getter to get m_currentOperation variable
     * @return m_currentOperation
     */
    public String getCurrentExpression() {
        return this.m_currentOperation;
    }

    /**
     * getter to get m_answerText variable
     * @return m_answerText
     */
    public String getAnswer() {
        return this.m_answerText;
    }

    /**
     * Reset variables to default value
     */
    private void reset() {
        this.m_currentOperation = "0";
        this.m_answerText = "";
        this.m_typeLastToken = TOKEN_NUMBER;
        this.m_converter.clean();
        this.m_parenthesis = 0;
        this.m_currentToken = "0";
        this.m_operatorToken = "";
        this.m_equalApplied = false;
        this.m_dotUsed = false;
        this.m_error = false;
    }

    /**
     * It will format the value
     * Used to remove 42.0 for example and 42.33333333333...33
     * If the number is too big, format it with x.Ey format
     * @param value value we want to format
     * @return string formated
     */
    private String formatString(double value) {
        if (!this.m_error) {
            NumberFormat format;
            if (value > 1000000) {
                format = new DecimalFormat("0.########E0");
            } else {
                format = new DecimalFormat("0.########");
            }
            return (String.valueOf(format.format(value)));
        } else {
            return "Error";
        }
    }

    /**
     * Helper to notify observers
     * @param obj: object we will notify
     */
    private void notifyViaObservable(Object obj) {
        setChanged();
        notifyObservers(obj);
    }
}
