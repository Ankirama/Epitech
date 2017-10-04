<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<div class="col-sm-3">
    <div class="left-sidebar">
        <h2>Categories</h2>
        <div class="panel-group category-products" id="accordian">
            <c:forEach items="${categories}" var="category" varStatus="status">
                <div class="panel panel-default">
                    <div class="panel-heading">
                        <h4 class="panel-title"><a href="/products/<c:out value='${category.slug}' />"><c:out value="${category.name}"/></a></h4>
                    </div>
                </div>
            </c:forEach>
        </div>
    </div>
</div>
