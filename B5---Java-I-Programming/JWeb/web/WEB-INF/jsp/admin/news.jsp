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
                <h2 class="title text-center">Display News infos</h2>
                    <c:forEach items="${news}" var="detail" varStatus="status">
                        <div class="display_addresses">
                            <ul>
                                <li>
                                    <c:out value="${detail.title}" />
                                    <span><a href="/deleteNews/<c:out value='${detail.id}' />">&times; remove</a></span>
                                </li>
                            </ul>
                        </div>
                    </c:forEach>
            </div>
        </div>
    </div>
</section>
<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>