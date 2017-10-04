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
                <h2 class="title text-center">Informations</h2>
                <p>This panel will allow you to administrate your e-commerce website.</p>
                <p>Enjoy!</p>
            </div>
        </div>
    </div>
</section>
<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>