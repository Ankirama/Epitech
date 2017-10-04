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
                <h2 class="title text-center">Display Accounts</h2>
                <h2 class="text-center">Accounts enabled</h2>
                <c:forEach items="${users}" var="user" varStatus="status">
                    <c:if test="${user.active == true && user.admin == false}">
                        <div class="display_addresses">
                            <ul>
                                <li>
                                    <c:out value="${user.username}" />
                                    <span><a href="/deleteAccount/<c:out value='${user.username}' />">&times; dissable</a></span>
                                </li>
                            </ul>
                        </div>
                    </c:if>
                </c:forEach>
                <br />
                <br />
                <h2 class="text-center">Accounts disabled</h2>
                <c:forEach items="${users}" var="user" varStatus="status">
                    <c:if test="${user.active == false && user.admin == false}">
                        <div class="display_addresses">
                            <ul>
                                <li>
                                    <c:out value="${user.username}" />
                                    <span><a href="/enableAccount/<c:out value='${user.id}' />">&times; enable</a></span>
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