<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!-- Modal -->
<div id="messageModal" class="modal fade" role="dialog">
    <div class="modal-dialog">

        <!-- Modal content-->
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal">&times;</button>
                <h4 class="modal-title" style="color: red">Warning</h4>
            </div>
            <div class="modal-body">
                <p><c:out value="${message}" /></p>
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-default" data-dismiss="modal">Ok</button>
            </div>
        </div>

    </div>
</div>
<%@ include file="/static/jsp/JSinclude.jsp" %>

<c:if test="${message != null}">
    <script type="text/javascript">
        $(window).load(function(){
            $('#messageModal').modal('show');
        });
    </script>
</c:if>