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
                <h2 class="title text-center">Views addresses</h2>
                <c:forEach items="${addresses}" var="address" varStatus="status">
                    <div class="col-sm-6 col-sm-offset-3">
                        <h2 class="text-center">Address ID <c:out value="${status.index + 1}" /></h2>
                        <div class="display_addresses">
                            <ul>
                                <li>
                                    Name
                                    <span><c:out value="${address.name}" /></span>
                                </li>
                                <li>
                                    First Name
                                    <span><c:out value="${address.firstName}" /></span>
                                </li>
                                <li>
                                    Last Name
                                    <span><c:out value="${address.lastName}" /></span>
                                </li>
                                <li>
                                    Address1
                                    <span><c:out value="${address.address1}" /></span>
                                </li>
                                <li>
                                    Address2
                                    <span><c:out value="${address.address2}" /></span>
                                </li>
                                <li>
                                    City
                                    <span><c:out value="${address.city}" /></span>
                                </li>
                                <li>
                                    Country
                                    <span><c:out value="${address.country}" /></span>
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
