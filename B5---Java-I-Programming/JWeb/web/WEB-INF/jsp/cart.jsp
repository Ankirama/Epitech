<html>
<head>
    <%@ include file="/static/jsp/headInclude.jsp" %>
</head><!--/head-->
<body>
<%@ include file="/static/jsp/elements/header.jsp" %>

<section id="cart_items">
    <div class="container">
        <div class="table-responsive cart_info">
            <table class="table table-condensed">
                <thead>
                <tr class="cart_menu">
                    <td class="description">Item</td>
                    <td class="price">Price</td>
                    <td class="quantity">Quantity</td>
                    <td class="total">Total</td>
                </tr>
                </thead>
                <tbody>
                <c:forEach items="${products}" var="product">
                    <tr>
                        <td class="cart_description">
                            <h4><a href="/product/${product.id}">${product.name}</a></h4>
                            <p>Web ID: ${product.id}</p>
                        </td>
                        <td class="cart_price">
                            <p>$${product.price}</p>
                        </td>
                        <td class="cart_quantity">
                            <div class="cart_quantity_button">
                                <input class="cart_quantity_input" readonly type="text" name="quantity" value="${product.quantity}" autocomplete="off" size="2">
                            </div>
                        </td>
                        <td class="cart_total">
                            <p class="cart_total_price">$${product.total}</p>
                        </td>
                    </tr>
                </c:forEach>
                </tbody>
            </table>
        </div>
    </div>
</section> <!--/#cart_items-->

<section id="do_action">
    <div class="container">
        <form action="/checkout" method="POST">
            <div class="row">
                <div class="col-sm-6">
                    <div class="chose_area">
                        <ul class="user_info">
                            <li class="single_field">
                                <label>Address:</label>
                                <select name="address">
                                    <c:forEach items="${addresses}" var="address">
                                        <option value="${address.name}"><c:out value="${address.name}"/> </option>
                                    </c:forEach>
                                </select>

                            </li>
                            <li class="single_field">
                                <label>Payment:</label>
                                <select name="payment">
                                    <c:forEach items="${payments}" var="payment">
                                        <option value="${payment.name}"><c:out value="${payment.name}"/></option>
                                    </c:forEach>
                                </select>

                            </li>
                        </ul>
                        <a class="btn btn-default update" href="/newAddress">Add a new address</a>
                        <a class="btn btn-default check_out" href="/newPayment">Add a new payment</a>
                    </div>
                </div>
                <div class="col-sm-6">
                    <div class="total_area">
                        <ul>
                            <li>Cart Sub Total <span>$${totalPrice}</span></li>
                            <li>Shipping Cost <span>Free</span></li>
                            <li>Total <span>$${totalPrice}</span></li>
                        </ul>
                        <input type="hidden" value="${totalPrice}" name="total" />
                        <button type="submit" class="btn btn-default check_out text-center">Check out</button>
                    </div>
                </div>
            </div>
        </form>
    </div>
</section><!--/#do_action-->

<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>