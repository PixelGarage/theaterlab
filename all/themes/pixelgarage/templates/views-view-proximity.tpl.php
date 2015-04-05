<?php
/**
 * @file
 * Default view template to display items in a proximity layout.
 */
?>

<div class="pe-container">
  <div class="pe-background-image"></div>

  <?php foreach ($rows as $id => $row): ?>

    <div class="pe-item <?php print 'pe-item-' . $id; ?> <?php if ($classes_array[$id]) print $classes_array[$id]; ?>" style="margin-left: -4px;width: <?php print $percentage_width; ?>%">
      <div class="pe-item-inner">
        <!-- modal trigger -->
        <a class="btn" role="button" data-toggle="modal" data-target="<?php print '#pe-modal-' . $id; ?>">
          <?php print $row; ?>
        </a>
      </div>
    </div>

    <!-- Modal -->
    <div id="<?php print 'pe-modal-' . $id; ?>" class="modal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
      <div class="modal-dialog">
        <div class="modal-content">
          <!-- Header -->
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
            <h4 class="modal-title" id="myModalLabel"><?php print $titles[$id]; ?></h4>
          </div>
          <!-- Body -->
          <div class="modal-body">
            <?php print $rendered_nodes[$id]; ?>
          </div>
          <!-- Footer -->
          <div class="modal-footer">
            <button type="button" class="btn btn-default" data-dismiss="modal"><?php print $close_text; ?></button>
          </div>

        </div>
      </div>
    </div>

  <?php endforeach; ?>
</div>
