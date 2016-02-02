<div class="noResults">
  <div class="noResults__heading">
    <h2>Nous n'avons pas trouvé de résultats correspondant à votre recherche.</h2>
    <p>Recherchiez-vous :</p>
  </div>
  <div class="noResults__category">
    <div class="noResults__category__list">

      <?php if(!empty($ville)): ?>
        <ul>
          <li><dl><dt><?php echo t('Ville'); ?></dt><dd><ul>
            <?php foreach($ville as $object): ?>
              <li><a href="<?php echo $object['link']; ?>" ><?php echo $object['name']; ?></a></li>
            <?php endforeach; ?>
          </ul></dd></dl></li>
        </ul>
      <?php endif; ?>

      <?php if(!empty($departement)): ?>
        <ul>
          <li><dl><dt><?php echo t('Département'); ?></dt><dd><ul>
            <?php foreach($departement as $object): ?>
              <li><a href="<?php echo $object['link']; ?>" ><?php echo $object['name']; ?></a></li>
            <?php endforeach; ?>
          </ul></dd></dl></li>
        </ul>
      <?php endif; ?>

      <?php if(!empty($region)): ?>
        <ul>
          <li><dl><dt><?php echo t('Région'); ?></dt><dd><ul>
            <?php foreach($region as $object): ?>
              <li><a href="<?php echo $object['link']; ?>" ><?php echo $object['name']; ?></a></li>
            <?php endforeach; ?>
          </ul></dd></dl></li>
        </ul>
      <?php endif; ?>

      <?php if(!empty($programme)): ?>
        <ul>
          <li><dl><dt><?php echo t('Programme'); ?></dt><dd><ul>
          <?php foreach($programme as $object): ?>
            <li><a href="<?php echo $object['link']; ?>" ><?php echo $object['name']; ?></a></li>
          <?php endforeach; ?>
          </ul></dd></dl></li>
        </ul>
      <?php endif; ?>

      <?php if(!empty($postal_code)): ?>
        <ul>
          <li><dl><dt><?php echo t('Code postal'); ?></dt><dd><ul>
          <?php foreach($postal_code as $object): ?>
            <li><a href="<?php echo $object['link']; ?>" ><?php echo $object['name']; ?></a></li>
          <?php endforeach; ?>
          </ul></dd></dl></li>
        </ul>
      <?php endif; ?>

    </div>
  </div>
</div>
