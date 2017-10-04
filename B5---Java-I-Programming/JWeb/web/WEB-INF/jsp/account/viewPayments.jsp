<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <%@ include file="/static/jsp/headInclude.jsp" %>
</head><!--/head-->
<body>
<%@ include file="/static/jsp/elements/header.jsp" %>
<section>
    <div class="container">
        <div class="row">
            <%@ include file="/static/jsp/elements/accountCategories.jsp" %>
            <div class="col-sm-9 padding-right">
                <h2 class="title text-center">Views Payments</h2>
                <c:forEach items="${payments}" var="payment" varStatus="status">
                    <div class="col-sm-6 col-sm-offset-3">
                        <h2 class="text-center">Payment ID <c:out value="${status.index + 1}" /></h2>
                        <div class="display_addresses">
                            <ul>
                                <li>
                                    Name
                                    <span><c:out value="${payment.name}" /></span>
                                </li>
                                <li>
                                    First Name
                                    <span><c:out value="${payment.first_name}" /></span>
                                </li>
                                <li>
                                    Last Name
                                    <span><c:out value="${payment.last_name}" /></span>
                                </li>
                                <li>
                                    Card Numbers
                                    <span><c:out value="${payment.card_numbers}" /></span>
                                </li>
                            </ul>
                        </div>
                    </div>
                    <br />
                    <br />
                </c:forEach>
            </div>
        </div>
    </div>
</section>
<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>
