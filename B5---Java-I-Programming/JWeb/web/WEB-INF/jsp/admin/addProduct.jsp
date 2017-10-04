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
                <h2 class="title text-center">Add a product</h2>
                <div class="col-sm-6 col-sm-offset-3">
                    <div class="contact-form">
                        <form id="main-contact-form" class="contact-form row" action="addProduct" name="contact-form" method="POST" enctype="multipart/form-data">
                            <div class="form-group col-md-12">
                                <input type="text" name="name" class="form-control" required="required" placeholder="Name">
                            </div>
                            <div class="form-group col-md-12">
                                <select name="categoryid" class="form-control" required="required">
                                    <c:forEach items="${categories}" var="category">
                                        <option value="<c:out value='${category.id}'/>"><c:out value="${category.name}"/></option>
                                    </c:forEach>
                                </select>
                            </div>
                            <div class="form-group col-md-12">
                                Price ($):
                                <input type="number" name="price" class="form-control" value="42" min="0">
                            </div>
                            <div class="form-group col-md-12">
                                <input type="file" name="illustration" class="form-control" required="required" style="padding-top: 7px!important;" />
                            </div>
                            <div class="form-group col-md-12">
                                <textarea name="description" id="description" required="required" class="form-control" rows="3" placeholder="Description here."></textarea>
                            </div>
                            <div class="form-group col-md-12">
                                <input type="submit" name="submit" class="btn btn-primary pull-right" value="Add product">
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