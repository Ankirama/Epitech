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
                <h2 class="title text-center">Add a category</h2>
                <div class="col-sm-6 col-sm-offset-3">
                    <div class="contact-form">
                        <form id="main-contact-form" class="contact-form row" action="addCategory" name="contact-form" method="POST">
                            <div class="form-group col-md-12">
                                <input type="text" name="category" class="form-control" required="required" placeholder="Name">
                            </div>
                            <div class="form-group col-md-12">
                                <input type="submit" name="submit" class="btn btn-primary pull-right" value="Add category">
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>
<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>