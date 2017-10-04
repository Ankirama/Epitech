<html>
<head>
    <%@ include file="/static/jsp/headInclude.jsp" %>
</head><!--/head-->
<body>
<%@ include file="/static/jsp/elements/header.jsp" %>

<section>
    <div class="container">
        <div class="row">
            <%@ include file="/static/jsp/elements/productCategories.jsp" %>

            <div class="col-sm-9 padding-right">
                <div class="blog-post-area">
                    <h2 class="title text-center">Latest From our News</h2>
                    <c:forEach items="${news}" var="detail" varStatus="status">
                        <div class="single-blog-post">
                            <h3><c:out value="${detail.title}"/></h3>
                            <div class="post-meta">
                                <ul>
                                    <li><i class="fa fa-user"></i><c:out value="${detail.author}"/></li>
                                    <li><i class="fa fa-calendar"></i><c:out value="${detail.date}"/></li>
                                </ul>
                            </div>
                            <a href="#">
                                <img src="<c:out value='${detail.illustration}'/>" alt="" style="max-height: 353px; width: auto;">
                            </a>
                            <p><c:out value="${detail.content}"/></p>
                        </div>
                    </c:forEach>
                </div>
            </div>
        </div>
    </div>
</section>

<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>