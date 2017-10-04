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
            <%@ include file="/static/jsp/elements/adminCategories.jsp" %>
            <div class="col-sm-9 padding-right">
                <h2 class="title text-center">Display products</h2>
                <h2 class="text-center">Products enabled</h2>
                <c:forEach items="${products}" var="product" varStatus="status">
                    <c:if test="${product.active == true}">
                        <div class="display_addresses">
                            <ul>
                                <li>
                                    ID <c:out value="${product.id}" />
                                    <span><a href="/updateProduct/<c:out value='${product.id}'/>">Update product</a></span>
                                </li>
                                <li>
                                    Name
                                    <span><c:out value="${product.name}"/></span>
                                </li>
                                <li>
                                    Price
                                    <span>$<c:out value="${product.price}"/></span>
                                </li>
                                <li>
                                    Active
                                    <span><a href="/deleteProduct/<c:out value='${product.id}' />">&times; disable</a></span>
                                </li>
                            </ul>
                        </div>
                    </c:if>
                </c:forEach>
                <h2 class="text-center">Products disabled</h2>
                <c:forEach items="${products}" var="product" varStatus="status">
                    <c:if test="${product.active == false}">
                        <div class="display_addresses">
                            <ul>
                                <li>
                                    ID <c:out value="${product.id}" />
                                    <span><a href="/updateProduct/<c:out value='${product.id}'/>">Update product</a></span>
                                </li>
                                <li>
                                    Name
                                    <span><c:out value="${product.name}"/></span>
                                </li>
                                <li>
                                    Price
                                    <span>$<c:out value="${product.price}"/></span>
                                </li>
                                <li>
                                    Active
                                    <span><a href="/enableProduct/<c:out value='${product.id}' />">&times; enable</a></span>
                                </li>
                            </ul>
                        </div>
                    </c:if>
                </c:forEach>
            </div>
        </div>
    </div>
</section>
<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>