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
            <h2 class="title text-center">Upadte your profile</h2>
            <div class="col-sm-6 col-sm-offset-3 login-form">
                <form action="" method="POST">
                    <input type="text" name="username" value="<c:out value='${sessionScope.user.username}' />" readonly/>
                    <input type="email" name="email" value="<c:out value='${sessionScope.user.email}' />" readonly/>
                    <c:choose>
                        <c:when test="${sessionScope.user.firstName == null || sessionScope.user.firstName.length() == 0}">
                            <input type="text" placeholder="First name" name="firstName" />
                        </c:when>
                        <c:otherwise>
                            <input type="text" placeholder="First name" value="<c:out value='${sessionScope.user.firstName}' />" name="firstName" />
                        </c:otherwise>
                    </c:choose>
                    <c:choose>
                        <c:when test="${sessionScope.user.firstName == null || sessionScope.user.lastName.length() == 0}">
                            <input type="text" placeholder="Last name" name="lastName" />
                        </c:when>
                        <c:otherwise>
                            <input type="text" placeholder="Last name" value="<c:out value='${sessionScope.user.lastName}' />" name="lastName" />
                        </c:otherwise>
                    </c:choose>
                    <span>
                        <c:choose>
                            <c:when test="${sessionScope.newsletterUser != null && sessionScope.newsletterUser == true}">
                                <input type="checkbox" checked="checked" class="checkbox" name="newsletter"/>
                            </c:when>
                            <c:otherwise>
                                <input type="checkbox" class="checkbox" name="newsletter" />
                            </c:otherwise>
                        </c:choose>
                        Newsletter
                    </span>
                    <div>
                        <button type="submit" name="update" value="Update" class="btn btn-default">Update</button>
                    </div>
                </form>
            </div>
        </div>
        <div class="col-sm-3"></div>
        <div class="col-sm-9 padding-right">
            <h2 class="title text-center">Delete your profile</h2>
            <div class="col-sm-4 col-sm-offset-4 login-form">
                <a href="/deleteAccount/<c:out value='${sessionScope.user.username}'/>"><button type="button" name="delete" value="Delete" class="btn btn-default" style="background: red!important; width: 100%;">Delete your account</button></a>
                <br />
                <br />
                <br />
            </div>
        </div>
    </div>
</div>
</section>
<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>